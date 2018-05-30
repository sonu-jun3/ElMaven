#ifndef UPLOADDATA_H
#define UPLOADDATA_H

#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/Bucket.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class uploadData {
public:
    uploadData(Aws::String filename);
    Aws::String getKeyname();
    bool compare(Aws::String a, Aws::String b);
protected:
private:
    bool bucketExists = false;
    Aws::String keyname;
    const Aws::String bucketname = "maven-user-data";
    bool checkBucket();
};

#endif
