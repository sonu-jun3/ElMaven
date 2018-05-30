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
#include <aws/states/SFN_EXPORTS.h>
#include <aws/states/SFNRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace SFN
{
namespace Model
{

  /**
   */
  class AWS_SFN_API SendTaskFailureRequest : public SFNRequest
  {
  public:
    SendTaskFailureRequest();
    
    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "SendTaskFailure"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The token that represents this task. Task tokens are generated by the service
     * when the tasks are assigned to a worker (see GetActivityTask::taskToken).</p>
     */
    inline const Aws::String& GetTaskToken() const{ return m_taskToken; }

    /**
     * <p>The token that represents this task. Task tokens are generated by the service
     * when the tasks are assigned to a worker (see GetActivityTask::taskToken).</p>
     */
    inline void SetTaskToken(const Aws::String& value) { m_taskTokenHasBeenSet = true; m_taskToken = value; }

    /**
     * <p>The token that represents this task. Task tokens are generated by the service
     * when the tasks are assigned to a worker (see GetActivityTask::taskToken).</p>
     */
    inline void SetTaskToken(Aws::String&& value) { m_taskTokenHasBeenSet = true; m_taskToken = std::move(value); }

    /**
     * <p>The token that represents this task. Task tokens are generated by the service
     * when the tasks are assigned to a worker (see GetActivityTask::taskToken).</p>
     */
    inline void SetTaskToken(const char* value) { m_taskTokenHasBeenSet = true; m_taskToken.assign(value); }

    /**
     * <p>The token that represents this task. Task tokens are generated by the service
     * when the tasks are assigned to a worker (see GetActivityTask::taskToken).</p>
     */
    inline SendTaskFailureRequest& WithTaskToken(const Aws::String& value) { SetTaskToken(value); return *this;}

    /**
     * <p>The token that represents this task. Task tokens are generated by the service
     * when the tasks are assigned to a worker (see GetActivityTask::taskToken).</p>
     */
    inline SendTaskFailureRequest& WithTaskToken(Aws::String&& value) { SetTaskToken(std::move(value)); return *this;}

    /**
     * <p>The token that represents this task. Task tokens are generated by the service
     * when the tasks are assigned to a worker (see GetActivityTask::taskToken).</p>
     */
    inline SendTaskFailureRequest& WithTaskToken(const char* value) { SetTaskToken(value); return *this;}


    /**
     * <p>An arbitrary error code that identifies the cause of the failure.</p>
     */
    inline const Aws::String& GetError() const{ return m_error; }

    /**
     * <p>An arbitrary error code that identifies the cause of the failure.</p>
     */
    inline void SetError(const Aws::String& value) { m_errorHasBeenSet = true; m_error = value; }

    /**
     * <p>An arbitrary error code that identifies the cause of the failure.</p>
     */
    inline void SetError(Aws::String&& value) { m_errorHasBeenSet = true; m_error = std::move(value); }

    /**
     * <p>An arbitrary error code that identifies the cause of the failure.</p>
     */
    inline void SetError(const char* value) { m_errorHasBeenSet = true; m_error.assign(value); }

    /**
     * <p>An arbitrary error code that identifies the cause of the failure.</p>
     */
    inline SendTaskFailureRequest& WithError(const Aws::String& value) { SetError(value); return *this;}

    /**
     * <p>An arbitrary error code that identifies the cause of the failure.</p>
     */
    inline SendTaskFailureRequest& WithError(Aws::String&& value) { SetError(std::move(value)); return *this;}

    /**
     * <p>An arbitrary error code that identifies the cause of the failure.</p>
     */
    inline SendTaskFailureRequest& WithError(const char* value) { SetError(value); return *this;}


    /**
     * <p>A more detailed explanation of the cause of the failure.</p>
     */
    inline const Aws::String& GetCause() const{ return m_cause; }

    /**
     * <p>A more detailed explanation of the cause of the failure.</p>
     */
    inline void SetCause(const Aws::String& value) { m_causeHasBeenSet = true; m_cause = value; }

    /**
     * <p>A more detailed explanation of the cause of the failure.</p>
     */
    inline void SetCause(Aws::String&& value) { m_causeHasBeenSet = true; m_cause = std::move(value); }

    /**
     * <p>A more detailed explanation of the cause of the failure.</p>
     */
    inline void SetCause(const char* value) { m_causeHasBeenSet = true; m_cause.assign(value); }

    /**
     * <p>A more detailed explanation of the cause of the failure.</p>
     */
    inline SendTaskFailureRequest& WithCause(const Aws::String& value) { SetCause(value); return *this;}

    /**
     * <p>A more detailed explanation of the cause of the failure.</p>
     */
    inline SendTaskFailureRequest& WithCause(Aws::String&& value) { SetCause(std::move(value)); return *this;}

    /**
     * <p>A more detailed explanation of the cause of the failure.</p>
     */
    inline SendTaskFailureRequest& WithCause(const char* value) { SetCause(value); return *this;}

  private:

    Aws::String m_taskToken;
    bool m_taskTokenHasBeenSet;

    Aws::String m_error;
    bool m_errorHasBeenSet;

    Aws::String m_cause;
    bool m_causeHasBeenSet;
  };

} // namespace Model
} // namespace SFN
} // namespace Aws
