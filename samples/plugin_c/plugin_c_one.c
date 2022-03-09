#include <stdlib.h>
#include <string.h>

#include "plugin_c_internal.h"

PluginContext* fn_create_plugin_context() {
    PluginContext* ctx = (PluginContext*)malloc(sizeof(PluginContext));
    if (ctx == NULL) {
        return NULL;
    }
    memset(ctx, 0, sizeof(PluginContext));
    ctx->objects = NULL;
    return ctx;
}

void fn_destroy_plugin_context(PluginContext** ctx) {
    free(*ctx);
    *ctx = NULL;
}