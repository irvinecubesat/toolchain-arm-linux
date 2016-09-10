// All of ADCS cmds

#ifndef ADCS_CMD_H
#define ADCS_CMD_H

#define ADCS_BDOT_NOT_RUNNING 1
#define ADCS_BDOT_ALREADY_RUNNING 2
#define ADCS_BDOT_BAD_PARAM_LEN 3
#define ADCS_BDOT_NOT_ENABLED 4
#define ADCS_NOT_INITIALIZED 5
#define ADCS_TLE_NOT_ENABLED 6
#define ADCS_TLE_INVALID 7
#define ADCS_WHEEL_NOT_ENABLED 8
#define ADCS_DRIVER_ERROR 9
#define ADCS_SPEED_ACCEL_MISMATCH 10
#define ADCS_BAD_SENSOR 11
#define ADCS_BAD_OPERATION 12
#define ADCS_IGRF_NOT_ENABLED 13
#define ADCS_DAMPENING_ALREADY_RUNNING 14
#define ADCS_DAMPENING_BAD_PARAM_LEN 15
#define ADCS_DAMPENING_NOT_RUNNING 16
#define ADCS_KALMAN_BAD_PARAM_LEN 17
#define ADCS_KALMAN_NOT_ENABLED 18
#define ADCS_KALMAN_OLD_SEQUENCE_NUM 19
#define ADCS_PD_NOT_RUNNING 20
#define ADCS_PD_ALREADY_RUNNING 21
#define ADCS_PD_BAD_PARAM_LEN 22

#define ADCS_NEG_X_FACE 0x01
#define ADCS_POS_X_FACE 0x02
#define ADCS_NEG_Y_FACE 0x04
#define ADCS_POS_Y_FACE 0x08
#define ADCS_NEG_Z_FACE 0x10
#define ADCS_POS_Z_FACE 0x20
#define ADCS_BOOM0_FACE 0x40
#define ADCS_BOOM1_FACE 0x80

#define ADCS_DETAIL_CMD 2
#define ADCS_DETAIL_RESP (ADCS_DETAIL_CMD | 0x80)

#define ADCS_LOCK_TORQUER_COILS_CMD 20
#define ADCS_LOCK_TORQUER_COILS_RESP (ADCS_LOCK_TORQUER_COILS_CMD | 0x80)

#define ADCS_BDOT_OFF_CMD 21
#define ADCS_BDOT_OFF_RESP (ADCS_BDOT_OFF_CMD | 0x80)

#define ADCS_BDOT_ON_CMD 22
#define ADCS_BDOT_ON_RESP (ADCS_BDOT_ON_CMD | 0x80)

#define ADCS_TORQUING_OFF_CMD 23
#define ADCS_TORQUING_OFF_RESP (ADCS_TORQUING_OFF_CMD | 0x80)

#define ADCS_SET_TLE_CMD 24
#define ADCS_SET_TLE_RESP (ADCS_SET_TLE_CMD | 0x80)

#define ADCS_RAMP_WHEEL_SPEED_CMD 25
#define ADCS_RAMP_WHEEL_SPEED_RESP (ADCS_RAMP_WHEEL_SPEED_CMD | 0x80)

#define ADCS_SET_SENSOR_STATE_CMD 26
#define ADCS_SET_SENSOR_STATE_RESP (ADCS_SET_SENSOR_STATE_CMD | 0x80)
#define ADCS_SENSOR_TYPE_MAG 1
#define ADCS_SENSOR_TYPE_SOL 2
#define ADCS_SENSOR_OP_ADD 1
#define ADCS_SENSOR_OP_RM 2
#define ADCS_SENSOR_OP_REPLACE 3
#define ADCS_SENSOR_OP_ADD_PASSIVE 4

#define ADCS_RELOAD_IGRF_CMD 27
#define ADCS_RELOAD_IGRF_RESP (ADCS_RELOAD_IGRF_CMD | 0x80)

#define ADCS_DAMPENING_ON_CMD 28
#define ADCS_DAMPENING_ON_RESP (ADCS_DAMPENING_ON_CMD | 0x80)

#define ADCS_DAMPENING_OFF_CMD 29
#define ADCS_DAMPENING_OFF_RESP (ADCS_DAMPENING_OFF_CMD | 0x80)

#define ADCS_BDOT_DEBUG_CMD 30
#define ADCS_BDOT_DEBUG_RESP (ADCS_BDOT_DEBUG_CMD | 0x80)
#define ADCS_BDOT_DEBUG_DATA 31

#define ADCS_KALMAN_CMD 32
#define ADCS_KALMAN_RESP (ADCS_KALMAN_CMD | 0x80)

#define ADCS_SET_MAIN_PARAMS_CMD 33
#define ADCS_SET_MAIN_PARAMS_RESP (ADCS_SET_MAIN_PARAMS_CMD | 0x80)

#define ADCS_PD_ON_CMD 34
#define ADCS_PD_ON_RESP (ADCS_PD_ON_CMD | 0x80)

#define ADCS_PD_OFF_CMD 35
#define ADCS_PD_OFF_RESP (ADCS_PD_OFF_CMD | 0x80)

struct ADCSMagData {
   char valid;
   int32_t x_nT, y_nT, z_nT;
} __attribute__((packed));

struct ADCSSolarAngleData {
   char valid;
   uint32_t intensity;
   uint16_t x, y, z;
} __attribute__((packed));

// ADCS Status defined in status-structs.h
struct ADCSDetail {
   uint16_t version;
   uint32_t count;
   struct timeval posTime;
   double julianDate;
   double siderealTime;
   double eciX, eciY, eciZ;
   double velX, velY, velZ;
   double latitude, longitude, altitude; // in meters
   double q1, q2, q3, q4;
   double r1, r2, r3;
   int32_t wheelSpeed; // 24.8
   int32_t wheelAccel; // 9.23
   int32_t targetWheelSpeed;
   int32_t targetWheelAccel;
   uint8_t wheelDeltaErrCnt;
   uint32_t wheelLifetimeErrs;
   uint32_t wheelInstanceErrs;
   uint32_t wheelInstances;
   uint32_t tle_epoch;
   uint8_t ctrlMode;
   uint8_t activeMags;
   uint8_t passiveMags;
   uint8_t activeSols;
   uint8_t passiveSols;
   struct ADCSMagData curr_mag, px_mag, nx_mag, pz_mag, nz_mag, py_mag, ny_mag;
   struct ADCSMagData extra1_mag, extra2_mag, extra3_mag, extra4_mag;
   struct ADCSSolarAngleData curr_sol, nx_sol, px_sol, nz_sol, pz_sol;
   struct ADCSSolarAngleData ny_sol, py_sol;
} __attribute__((packed));

struct BdotParams {
   uint32_t maxIterations;
   uint32_t step_divisor;
   int32_t gainX, gainY, gainZ;
   uint32_t msTimeBetweenReads;
   uint32_t msTimeTorqueOn;
   uint8_t spinUp;
} __attribute__((packed));

struct BdotDebugParams {
   uint8_t debug_on;
   uint16_t port;
   uint32_t ip;
} __attribute__((packed));

struct BdotDebugData {
   struct ADCSMagData reading1, reading2;
   struct ADCSMagData px_mag, nx_mag, pz_mag, nz_mag, py_mag, ny_mag;
   struct ADCSMagData extra1_mag, extra2_mag, extra3_mag, extra4_mag;
   uint8_t activeMags;
   uint8_t passiveMags;
   uint8_t currentMag;
   uint8_t ctrlMode;
   uint32_t reading_delta_ms;
   uint32_t step_count;
   int32_t x_nT_torque, y_nT_torque, z_nT_torque;
   uint32_t torque_duration_msec;
   unsigned long ip;
   unsigned short port;
} __attribute__((packed));

struct SetTLEParams {
   uint8_t dont_save;
   char line1[70];
   char line2[70];
} __attribute__((packed));

struct WheelParams {
   int32_t finalWheelSpeed; // 24.8
   int32_t wheelAccel; // 9.23
} __attribute__((packed));

struct SensorStateParams {
   uint8_t sensor_type;
   uint8_t operation;
   uint8_t active;
   uint8_t passive;
} __attribute__((packed));

struct DampeningAxisParams {
   // Units are micro (10^-6) degrees per second
   int32_t high_gain;
   int32_t low_gain;
   int32_t high_mark;
   int32_t low_mark;
} __attribute__((packed));

struct DampeningParams {
   struct DampeningAxisParams roll;
   struct DampeningAxisParams pitch;
   struct DampeningAxisParams yaw;
   uint32_t msec_duration;
   uint32_t step_divisor;
   uint32_t iterations;
} __attribute__((packed));

struct IntFloat {
   int32_t whole;
   int32_t fraction;
} __attribute__((packed));

#define NIF_2_FLOAT(x) ( (double)((int32_t)ntohl((x)->whole)) + (double)((int32_t)ntohl((x)->fraction))/((double)INT32_MAX) )

#define ADCS_KALMAN_MODE_OFF 0
#define ADCS_KALMAN_MODE_ON 1
#define ADCS_KALMAN_MODE_INIT 2
#define ADCS_KALMAN_MODE_SV_INIT 3
#define ADCS_KALMAN_MODE_RESTART 4
#define ADCS_KALMAN_MODE_RELOAD 5

struct KalmanParams {
   uint8_t mode;
   uint32_t estep;
   uint32_t seqNum;
   struct IntFloat I1, I2, I3, Jw, n;
   struct IntFloat Q_val, Rm_val, Rb_val, P_val;
   struct IntFloat r1, r2, r3, q1, q2, q3, q4;
} __attribute__((packed));

struct MainADCSParams {
   uint32_t interval_ms;
   uint32_t sol_cutoff;
} __attribute__((packed));

struct PDParams {
   uint32_t msec_duration;
   uint32_t step_divisor;
   uint32_t iterations;
   uint32_t seqNum;
   struct IntFloat C1, C2, I1, I2, I3, cr1, cr2, cr3;
   struct IntFloat q_d1, q_d2, q_d3, q_d4;
} __attribute__((packed));

#endif
