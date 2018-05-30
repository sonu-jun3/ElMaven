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

#pragma once

#include <aws/core/client/CoreErrors.h>
#include <aws/ssm/SSM_EXPORTS.h>

namespace Aws
{
namespace SSM
{
enum class SSMErrors
{
  //From Core//
  //////////////////////////////////////////////////////////////////////////////////////////
  INCOMPLETE_SIGNATURE = 0,
  INTERNAL_FAILURE = 1,
  INVALID_ACTION = 2,
  INVALID_CLIENT_TOKEN_ID = 3,
  INVALID_PARAMETER_COMBINATION = 4,
  INVALID_QUERY_PARAMETER = 5,
  INVALID_PARAMETER_VALUE = 6,
  MISSING_ACTION = 7, // SDK should never allow
  MISSING_AUTHENTICATION_TOKEN = 8, // SDK should never allow
  MISSING_PARAMETER = 9, // SDK should never allow
  OPT_IN_REQUIRED = 10,
  REQUEST_EXPIRED = 11,
  SERVICE_UNAVAILABLE = 12,
  THROTTLING = 13,
  VALIDATION = 14,
  ACCESS_DENIED = 15,
  RESOURCE_NOT_FOUND = 16,
  UNRECOGNIZED_CLIENT = 17,
  MALFORMED_QUERY_STRING = 18,
  SLOW_DOWN = 19,
  REQUEST_TIME_TOO_SKEWED = 20,
  INVALID_SIGNATURE = 21,
  SIGNATURE_DOES_NOT_MATCH = 22,
  INVALID_ACCESS_KEY_ID = 23,
  NETWORK_CONNECTION = 99,
  
  UNKNOWN = 100,
  ///////////////////////////////////////////////////////////////////////////////////////////

  ALREADY_EXISTS= static_cast<int>(Aws::Client::CoreErrors::SERVICE_EXTENSION_START_RANGE) + 1,
  ASSOCIATED_INSTANCES,
  ASSOCIATION_ALREADY_EXISTS,
  ASSOCIATION_DOES_NOT_EXIST,
  ASSOCIATION_LIMIT_EXCEEDED,
  ASSOCIATION_VERSION_LIMIT_EXCEEDED,
  AUTOMATION_DEFINITION_NOT_FOUND,
  AUTOMATION_DEFINITION_VERSION_NOT_FOUND,
  AUTOMATION_EXECUTION_LIMIT_EXCEEDED,
  AUTOMATION_EXECUTION_NOT_FOUND,
  AUTOMATION_STEP_NOT_FOUND,
  COMPLIANCE_TYPE_COUNT_LIMIT_EXCEEDED,
  CUSTOM_SCHEMA_COUNT_LIMIT_EXCEEDED,
  DOCUMENT_ALREADY_EXISTS,
  DOCUMENT_LIMIT_EXCEEDED,
  DOCUMENT_PERMISSION_LIMIT,
  DOCUMENT_VERSION_LIMIT_EXCEEDED,
  DOES_NOT_EXIST,
  DUPLICATE_DOCUMENT_CONTENT,
  DUPLICATE_INSTANCE_ID,
  FEATURE_NOT_AVAILABLE,
  HIERARCHY_LEVEL_LIMIT_EXCEEDED,
  HIERARCHY_TYPE_MISMATCH,
  IDEMPOTENT_PARAMETER_MISMATCH,
  INVALID_ACTIVATION,
  INVALID_ACTIVATION_ID,
  INVALID_ALLOWED_PATTERN,
  INVALID_ASSOCIATION_VERSION,
  INVALID_AUTOMATION_EXECUTION_PARAMETERS,
  INVALID_AUTOMATION_SIGNAL,
  INVALID_AUTOMATION_STATUS_UPDATE,
  INVALID_COMMAND_ID,
  INVALID_DELETE_INVENTORY_PARAMETERS,
  INVALID_DELETION_ID,
  INVALID_DOCUMENT,
  INVALID_DOCUMENT_CONTENT,
  INVALID_DOCUMENT_OPERATION,
  INVALID_DOCUMENT_SCHEMA_VERSION,
  INVALID_DOCUMENT_VERSION,
  INVALID_FILTER,
  INVALID_FILTER_KEY,
  INVALID_FILTER_OPTION,
  INVALID_FILTER_VALUE,
  INVALID_INSTANCE_ID,
  INVALID_INSTANCE_INFORMATION_FILTER_VALUE,
  INVALID_INVENTORY_ITEM_CONTEXT,
  INVALID_INVENTORY_REQUEST,
  INVALID_ITEM_CONTENT,
  INVALID_KEY_ID,
  INVALID_NEXT_TOKEN,
  INVALID_NOTIFICATION_CONFIG,
  INVALID_OPTION,
  INVALID_OUTPUT_FOLDER,
  INVALID_OUTPUT_LOCATION,
  INVALID_PARAMETERS,
  INVALID_PERMISSION_TYPE,
  INVALID_PLUGIN_NAME,
  INVALID_RESOURCE_ID,
  INVALID_RESOURCE_TYPE,
  INVALID_RESULT_ATTRIBUTE,
  INVALID_ROLE,
  INVALID_SCHEDULE,
  INVALID_TARGET,
  INVALID_TYPE_NAME,
  INVALID_UPDATE,
  INVOCATION_DOES_NOT_EXIST,
  ITEM_CONTENT_MISMATCH,
  ITEM_SIZE_LIMIT_EXCEEDED,
  MAX_DOCUMENT_SIZE_EXCEEDED,
  PARAMETER_ALREADY_EXISTS,
  PARAMETER_LIMIT_EXCEEDED,
  PARAMETER_MAX_VERSION_LIMIT_EXCEEDED,
  PARAMETER_NOT_FOUND,
  PARAMETER_PATTERN_MISMATCH,
  PARAMETER_VERSION_NOT_FOUND,
  RESOURCE_DATA_SYNC_ALREADY_EXISTS,
  RESOURCE_DATA_SYNC_COUNT_EXCEEDED,
  RESOURCE_DATA_SYNC_INVALID_CONFIGURATION,
  RESOURCE_DATA_SYNC_NOT_FOUND,
  RESOURCE_IN_USE,
  RESOURCE_LIMIT_EXCEEDED,
  STATUS_UNCHANGED,
  SUB_TYPE_COUNT_LIMIT_EXCEEDED,
  TARGET_IN_USE,
  TOO_MANY_TAGS,
  TOO_MANY_UPDATES,
  TOTAL_SIZE_LIMIT_EXCEEDED,
  UNSUPPORTED_INVENTORY_ITEM_CONTEXT,
  UNSUPPORTED_INVENTORY_SCHEMA_VERSION,
  UNSUPPORTED_OPERATING_SYSTEM,
  UNSUPPORTED_PARAMETER_TYPE,
  UNSUPPORTED_PLATFORM_TYPE
};
namespace SSMErrorMapper
{
  AWS_SSM_API Aws::Client::AWSError<Aws::Client::CoreErrors> GetErrorForName(const char* errorName);
}

} // namespace SSM
} // namespace Aws
