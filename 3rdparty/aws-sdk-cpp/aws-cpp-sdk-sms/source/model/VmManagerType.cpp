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

#include <aws/sms/model/VmManagerType.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace SMS
  {
    namespace Model
    {
      namespace VmManagerTypeMapper
      {

        static const int VSPHERE_HASH = HashingUtils::HashString("VSPHERE");


        VmManagerType GetVmManagerTypeForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == VSPHERE_HASH)
          {
            return VmManagerType::VSPHERE;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<VmManagerType>(hashCode);
          }

          return VmManagerType::NOT_SET;
        }

        Aws::String GetNameForVmManagerType(VmManagerType enumValue)
        {
          switch(enumValue)
          {
          case VmManagerType::VSPHERE:
            return "VSPHERE";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace VmManagerTypeMapper
    } // namespace Model
  } // namespace SMS
} // namespace Aws
