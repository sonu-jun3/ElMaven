﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/mturk-requester/model/NotificationTransport.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace MTurk
  {
    namespace Model
    {
      namespace NotificationTransportMapper
      {

        static const int Email_HASH = HashingUtils::HashString("Email");
        static const int SQS_HASH = HashingUtils::HashString("SQS");
        static const int SNS_HASH = HashingUtils::HashString("SNS");


        NotificationTransport GetNotificationTransportForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == Email_HASH)
          {
            return NotificationTransport::Email;
          }
          else if (hashCode == SQS_HASH)
          {
            return NotificationTransport::SQS;
          }
          else if (hashCode == SNS_HASH)
          {
            return NotificationTransport::SNS;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<NotificationTransport>(hashCode);
          }

          return NotificationTransport::NOT_SET;
        }

        Aws::String GetNameForNotificationTransport(NotificationTransport enumValue)
        {
          switch(enumValue)
          {
          case NotificationTransport::Email:
            return "Email";
          case NotificationTransport::SQS:
            return "SQS";
          case NotificationTransport::SNS:
            return "SNS";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace NotificationTransportMapper
    } // namespace Model
  } // namespace MTurk
} // namespace Aws
