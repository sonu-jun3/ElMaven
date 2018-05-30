#include "uploadData.h"

//Compare two Aws::Strings; return true if same.
bool uploadData::compare(Aws::String a, Aws::String b) {
    unsigned int n = a.size();
    unsigned int m = b.size();
    unsigned int i = 0;
    unsigned int j = 0;
    bool equal = true;

    if (n == m) {
        while (i++ < n && j++ < m) {
            if (a[i] != b[j]) {
                equal = false;
                break;
            }
        }
    }
    else equal = false;

    return equal;
}

//Get keyname using user's system time.
Aws::String uploadData::getKeyname() {
    time_t systemTime = time(NULL);

    Aws::String localTime = ctime(&systemTime);
    Aws::String name;
    name.resize(localTime.size() - 1);

    for (size_t i = 0; i < localTime.size() - 1; i++) {
        if (localTime[i] == ' ' || localTime[i] == ':') {
            name[i] = '-';
        }
        else name[i] = localTime[i];
    }

    return name;
}

//Check the existence of bucket <bucketname>
bool uploadData::checkBucket() {
    bucketExists = false;

    Aws::SDKOptions options;
    Aws::InitAPI(options);
    {
        Aws::S3::S3Client s3Client;
        auto outcome = s3Client.ListBuckets();

        if (outcome.IsSuccess()) {
            Aws::Vector<Aws::S3::Model::Bucket> bucketList =
                outcome.GetResult().GetBuckets();

            for (auto const &bucket : bucketList) {
                if (compare(bucket.GetName(), bucketname)) {
                    bucketExists = true;
                    break;
                }
            }
        }
    }
    Aws::ShutdownAPI(options);

    return bucketExists;
}

//Constructor to upload file <filename> to bucket <bucketname> to AWS S3
uploadData::uploadData(Aws::String filename) {
    if (!bucketExists) bucketExists = checkBucket();

    if (bucketExists) {
        keyname = getKeyname();

        Aws::SDKOptions options;
        Aws::InitAPI(options);
        {
            Aws::Client::ClientConfiguration clientConfig;
            Aws::S3::S3Client s3Client(clientConfig);

            Aws::S3::Model::PutObjectRequest objectRequest;
            objectRequest.WithBucket(bucketname).WithKey(keyname);

            // Binary files must also have the std::ios_base::bin flag or'ed in
            auto inputData = Aws::MakeShared<Aws::FStream>("PutObjectInputStream",
                filename.c_str(), std::ios_base::in | std::ios_base::binary);

            objectRequest.SetBody(inputData);
            auto putObjectOutcome = s3Client.PutObject(objectRequest);

            if (!putObjectOutcome.IsSuccess()) {
                std::cout << "PutObject error: " <<
                    putObjectOutcome.GetError().GetExceptionName() << " " <<
                    putObjectOutcome.GetError().GetMessage() << std::endl;
            }
        }
        Aws::ShutdownAPI(options);
    }
}
