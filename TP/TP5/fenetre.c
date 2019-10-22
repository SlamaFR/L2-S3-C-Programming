#include <MLV/MLV_all.h>

int main(int argc, char* argv[]) {
    MLV_create_window("Fenêtre", "", 400, 300);
    MLV_update_window();
    MLV_wait_seconds(3);
    return 0;
}
