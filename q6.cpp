#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float temperature;
    float rainfall;
    float wind_speed;
} Weather;

typedef struct {
    char crop_type[50];
    char growth_stage[20];
    float expected_yield;
    Weather *weather_forecast;
} Crop;

typedef struct {
    char equipment_name[50];
    char operational_status[20];
    float fuel_level;
    char activity_schedule[100];
} Equipment;

typedef struct {
    float soil_nutrients;
    float pH_level;
    int pest_activity;
} Sensor;

typedef struct {
    float gps_coordinates[2];
    float soil_health_metrics;
    float moisture_levels;
    Crop *crops;
    int crop_count;
    Equipment *equipment;
    int equipment_count;
    Sensor *sensors;
    int sensor_count;
} Field;

typedef struct {
    char hub_name[50];
    Field *fields;
    int field_count;
    float aggregate_yield;
    float resource_distribution;
    char emergency_response_plan[100];
} RegionalHub;

typedef struct {
    RegionalHub *regional_hubs;
    int hub_count;
} AnalyticsServer;

int main() {
    int field_count = 2, crop_count = 2, equipment_count = 2, sensor_count = 2;

    Field *fields = (Field *)malloc(field_count * sizeof(Field));
    for (int i = 0; i < field_count; i++) {
        fields[i].crops = (Crop *)malloc(crop_count * sizeof(Crop));
        fields[i].equipment = (Equipment *)malloc(equipment_count * sizeof(Equipment));
        fields[i].sensors = (Sensor *)malloc(sensor_count * sizeof(Sensor));
        fields[i].crop_count = crop_count;
        fields[i].equipment_count = equipment_count;
        fields[i].sensor_count = sensor_count;
    }

    RegionalHub hub = {
        "Regional Hub 1",
        fields,
        field_count,
        0.0,
        0.0,
        ""
    };

    AnalyticsServer server = {
        &hub,
        1
    };

    printf("Analytics Server initialized with %d regional hub(s)\n", server.hub_count);
    printf("Regional Hub: %s with %d field(s)\n", hub.hub_name, hub.field_count);

    for (int i = 0; i < field_count; i++) {
        free(fields[i].crops);
        free(fields[i].equipment);
        free(fields[i].sensors);
    }
    free(fields);

    return 0;
}

