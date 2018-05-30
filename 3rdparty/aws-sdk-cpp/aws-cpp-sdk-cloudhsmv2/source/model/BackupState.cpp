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

#include <aws/cloudhsmv2/model/BackupState.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace CloudHSMV2
  {
    namespace Model
    {
      namespace BackupStateMapper
      {

        static const int CREATE_IN_PROGRESS_HASH = HashingUtils::HashString("CREATE_IN_PROGRESS");
        static const int READY_HASH = HashingUtils::HashString("READY");
        static const int DELETED_HASH = HashingUtils::HashString("DELETED");


        BackupState GetBackupStateForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == CREATE_IN_PROGRESS_HASH)
          {
            return BackupState::CREATE_IN_PROGRESS;
          }
          else if (hashCode == READY_HASH)
          {
            return BackupState::READY;
          }
          else if (hashCode == DELETED_HASH)
          {
            return BackupState::DELETED;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<BackupState>(hashCode);
          }

          return BackupState::NOT_SET;
        }

        Aws::String GetNameForBackupState(BackupState enumValue)
        {
          switch(enumValue)
          {
          case BackupState::CREATE_IN_PROGRESS:
            return "CREATE_IN_PROGRESS";
          case BackupState::READY:
            return "READY";
          case BackupState::DELETED:
            return "DELETED";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace BackupStateMapper
    } // namespace Model
  } // namespace CloudHSMV2
} // namespace Aws
