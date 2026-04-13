#include <stdio.h>
#include <string.h>

#define MAX_APPS 25

typedef struct {
    char name[50];
    char description[200];
    char install_command[100];
} App;

App app_store[MAX_APPS] = {
    {"App1", "Description for App1", "install App1"},
    {"App2", "Description for App2", "install App2"},
    {"App3", "Description for App3", "install App3"},
    {"App4", "Description for App4", "install App4"},
    {"App5", "Description for App5", "install App5"},
    {"App6", "Description for App6", "install App6"},
    {"App7", "Description for App7", "install App7"},
    {"App8", "Description for App8", "install App8"},
    {"App9", "Description for App9", "install App9"},
    {"App10", "Description for App10", "install App10"},
    {"App11", "Description for App11", "install App11"},
    {"App12", "Description for App12", "install App12"},
    {"App13", "Description for App13", "install App13"},
    {"App14", "Description for App14", "install App14"},
    {"App15", "Description for App15", "install App15"},
    {"App16", "Description for App16", "install App16"},
    {"App17", "Description for App17", "install App17"},
    {"App18", "Description for App18", "install App18"},
    {"App19", "Description for App19", "install App19"},
    {"App20", "Description for App20", "install App20"},
};

void list_apps() {
    printf("Available Applications:\n");
    for (int i = 0; i < MAX_APPS; i++) {
        if (strlen(app_store[i].name) > 0) {
            printf("%s: %s\n", app_store[i].name, app_store[i].description);
        }
    }
}

void install_app(const char *name) {
    for (int i = 0; i < MAX_APPS; i++) {
        if (strcmp(app_store[i].name, name) == 0) {
            printf("Installing %s...\n", app_store[i].name);
            // Simulate installation
            return;
        }
    }
    printf("Application %s not found.\n", name);
}

void uninstall_app(const char *name) {
    for (int i = 0; i < MAX_APPS; i++) {
        if (strcmp(app_store[i].name, name) == 0) {
            printf("Uninstalling %s...\n", app_store[i].name);
            // Simulate uninstallation
            return;
        }
    }
    printf("Application %s not found.\n", name);
}

void search_app(const char *name) {
    for (int i = 0; i < MAX_APPS; i++) {
        if (strstr(app_store[i].name, name) != NULL) {
            printf("Found: %s - %s\n", app_store[i].name, app_store[i].description);
        }
    }
}

int main() {
    list_apps();
    install_app("App1");
    uninstall_app("App1");
    search_app("App2");
    return 0;
}