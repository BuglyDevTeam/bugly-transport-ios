//
//  bugly_report_data_mode.h
//  Bugly
//
//  Created by Hua Xiang on 2024/02/21.
//


/// 用来定义各个上报所需的数据

#ifndef BUGLY_REPORT_DATA_MODE_H
#define BUGLY_REPORT_DATA_MODE_H

#include <vector>
#include <string>
#include <unordered_map>

namespace bugly {

struct BuglyReportInfoBase;
typedef void(*BuglyResponseHandle)(const std::string& baseType, const std::string& subType, int statusCode, const std::string& resp);

#pragma mark -- DAU
using SdkInfoType = std::vector<std::unordered_map<std::string, std::string>>;
struct BuglyReportInfoBase
{
    void*                    context{nullptr};
    bool                     sync{false};
    std::string              clientIdentify;
    std::string              baseType;
    std::string              subType;

    BuglyReportInfoBase() {}
    BuglyReportInfoBase(const BuglyReportInfoBase& other):context(other.context),sync(other.sync),
            clientIdentify(other.clientIdentify),baseType(other.baseType),subType(other.subType){}
    
    BuglyReportInfoBase(BuglyReportInfoBase&& other) noexcept {
        this->context          = other.context;
        this->clientIdentify   = std::move(other.clientIdentify);
        this->baseType         = std::move(other.baseType);
        this->subType          = std::move(other.subType);
    }
};

struct BulgyReportDauAttributes : public BuglyReportInfoBase
{
    std::vector<std::string> features_enabled;
    bool                     first_report;
    SdkInfoType              sdk_info;
};

#pragma mark -- Exception
struct BuglyReportExceptionInfo : public BuglyReportInfoBase
{
    std::string         name;
    std::string         message;
    std::string         addr;
    uint64_t            app_start_time;
    std::string         stack;
    std::string         thread;
    std::string         exceptionType;  // Dart:"109"
    uint64_t            sessionTimestamp;

    bool                isRunInFront;
};

#pragma mark -- LaunchMetric
struct BuglyReportLaunchMetricInfo : public BuglyReportInfoBase
{
    bool                isColdLaunch;
    uint64_t            launchCost;
    uint64_t            startTime;
    std::vector<std::string> tags;
    struct TraceSpan
    {
        std::string     traceId;
        std::string     spanId;
        std::string     parentSpanId;
        std::string     spanName;
        uint64_t        startTimeUnixMs;
        uint64_t        endTimeUnixMs;
        std::string     kind;
    };
    std::vector<TraceSpan> spans;
};

#pragma mark -- LooperMetric
struct BuglyReportLooperMetricInfo : public BuglyReportInfoBase
{
    struct MetricData {
        std::string         stage;
        uint64_t            totalDuration;
        uint64_t            hitchesDuration;
        uint64_t            suspendDuration;
        uint64_t            timestamp;
        uint64_t            totalRefreshCount;
        std::vector<uint64_t> refreshCounts;
        std::vector<uint64_t> refreshDuration;
    };
    std::vector<MetricData> metricDatas;
};

#pragma mark -- JankStack
struct BuglyReportJankStackInfo : public BuglyReportInfoBase
{
    uint64_t                TimeCost;
    uint64_t                StackInterval;
    std::string             stage;

    struct stack
    {
        std::string         type;
        std::string         threadName;
        std::string         threadId;
        uint32_t            repeatCount;
        uint32_t            index;
        uint64_t            timestamp;
        std::string         callStack;
    };

    std::vector<stack>      stacks;
};

#pragma mark -- network
struct BuglyReportNetQualityMetricInfo : public BuglyReportInfoBase
{
    uint64_t                launchDuration;
    struct metric {
        std::string         collectType;
        std::string         trafficType;
        std::string         peerName;
        std::string         frontState;
        std::string         netType;
        uint64_t            send;
        uint64_t            recv;
        uint64_t            startTime;
        uint64_t            endTime;
    };

    struct httpMetric : public metric {
        uint64_t            requestTimeInMs;
        std::string         protocol;
        bool                isHttps;
        std::string         host;
        std::string         path;
        std::string         queryString;
        std::string         method;
        std::string         stage;
        bool                isReuseConnection;
        int32_t             statusCode;
        int32_t             resultCode;
        uint64_t            totalCostInMs;
        uint64_t            sendBytes;
        uint64_t            recvBytes;
        uint32_t            dnsCostInMs;
        uint32_t            tcpCostInMs;
        uint32_t            sslCostInMs;
        uint32_t            requestCostInMs;
        uint32_t            waitCostInMs;
        uint32_t            responseCostInMs;
        uint32_t            firstPackageCostInMs;
        std::string         hostIP;
        uint32_t            hostPort;
        std::string         clientIP;
        uint32_t            clientPort;
        std::string         clientOperator;
        std::string         clientRegionId;
        std::string         exceptionType;
        std::string         callStack;
        std::unordered_map<std::string, std::string> userCustom;
    };
    

    std::vector<metric>      metrics;
    std::vector<httpMetric>  httpMetrics;
};


} //namespace

#endif //BUGLY_REPORT_DATA_MODE_H
