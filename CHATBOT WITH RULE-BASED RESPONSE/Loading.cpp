#include <iostream>
#include <unistd.h>
using namespace std;
void showProgressBar(int duration, int steps) {
    int progressBarWidth = 25;
    for (int i = 0; i < steps; ++i) {
        float progress = static_cast<float>(i) / steps;
        int barWidth = static_cast<int>(progress * progressBarWidth);
        cout << "[";
        for (int j = 0; j < progressBarWidth; ++j) {
            if (j < barWidth)
                cout << ".";
            else
                cout << " ";
        }
        cout << "] " << int(progress * 101.0) << "%\r";
        cout.flush();

        // Simulate some work being done
        usleep(duration * 1000);
    }
    cout << endl;
}
int main() {
    int loadingDuration = 100; // in milliseconds
    int numberOfSteps = 200;

    showProgressBar(loadingDuration, numberOfSteps);

    return 0;
}