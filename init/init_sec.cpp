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
    property_override("ro.product.model", "SM-J710F");
    property_override("ro.product.device", "j7xelte");
    property_override("ro.product.name", "j7xeltexx");
    property_override("ro.build.product", "j7xelte");
    property_override("ro.build.description", "j7xeltexx-user 7.0 NRD90M J710FXXU3BQJ3 release-keys");
    property_override("ro.build.fingerprint", "samsung/j7xeltexx/j7xelte:7.0/NRD90M/J710FXXU3BQJ3:user/release-keys");
}
