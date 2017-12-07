#include <stdio.h>
#include <stdlib.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "log.h"
#include "property_service.h"
#include "util.h"
#include "vendor_init.h"

static void property_override(char const prop[], char const value[]) {
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    property_override("ro.product.model", "SM-J701F");
    property_override("ro.product.device", "j7velte");
    property_override("ro.product.name", "j7veltedx");
    property_override("ro.build.product", "j7velte");
    property_override("ro.build.description", "j7veltedx-user 7.0 NRD90M J701FDDU1AQG1 release-keys");
    property_override("ro.build.fingerprint", "samsung/j7veltedx/j7velte:7.0/NRD90M/J701FDDU1AQG1:user/release-keys");
}
