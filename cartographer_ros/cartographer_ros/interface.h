/*** 
 * @Author: ljz
 * @Date: 2022-04-12 21:15:20
 * @LastEditTime: 2022-04-12 21:26:06
 * @LastEditors: ljz
 * @Description: 
 * @FilePath: /carto_ws/src/cartographer_ros/cartographer_ros/cartographer_ros/interface.h
 * @
 */

#include <vector>
#include <string>
#include <stdint.h>

typedef struct Vector3
{
    double x;
    double y;
    double z;
} Vector3;


typedef struct Quaternion
{
    double x;
    double y;
    double z;
    double w;
} Quaternion;

typedef struct Header
{
    uint32_t seq;    
    uint64_t stamp;       
    std::string frameId;
} Header;

typedef struct Twist
{
    Vector3 linear; 
    Vector3 angular;
} Twist;


typedef struct Pose
{
    Vector3 position; 
    Quaternion orientation;
} Pose;


typedef struct Odometry
{
    Header header;
    Pose pose;
    Twist twist;
    bool reliable=true;
} Odometry;

typedef struct LaserScan
{
    Header header;
    float angleMin;
    float angleMax;
    float angleIncrement;
    float timeIncrement;
    float scanTime;
    float rangeMin;
    float rangeMax;
    std::vector<float> ranges;
    std::vector<float> intensities;
    uint32_t scanLines;
} LaserScan;


typedef struct PoseStamped
{
    Header header;
    Vector3 position;   
    Quaternion orientation;
} PoseStamped;

typedef struct Imu
{
    Header header;
    Quaternion orientation;    // 四元数
    Vector3 angularVel;        // 单位rad/s
    Vector3 linearAcc;         // 单位m/s^2
} Imu;



// 坐标系转换关系
typedef struct Transform
{
    Header header;
    std::string childFrame;  // 子坐标系
    Vector3 translation;        // 坐标偏移
    Quaternion rotation;        // 角度偏转
} Transform;

typedef struct
{
    Pose pose;
    bool poseValid;
    bool noLaserData;
    bool laserPointsTooClose;
    bool laserPointsTooFar;
    int32_t reserve[16];
}CurrentPose;

extern CurrentPose pos_now;

// brief 获取当前的位姿

// param  pose 当前的位姿

// retun true 成功， false 失败

bool getPose(CurrentPose &pose);
