#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

class State {
    private:
      int current_sum = 0;
      int max_sum = 0;
      void finish_block() {
        if (current_sum > max_sum) max_sum = current_sum;
        current_sum = 0;
      }

    public:
      void process_line(const char* line) {
        printf("%s\n", line);
        if (std::strlen(line) < 1) {
            finish_block();
        } else {
            current_sum += std::stoi(line);
        }
      }

      void finished() {
        finish_block();
        printf("max block: %d\n", max_sum);
      }
};

int main(int, char**) {
    std::ifstream input;
    input.open("../input.txt");
    if (!input.is_open()) {
        fprintf(stderr, "Error opening input.txt");
        return EXIT_FAILURE;
    }

    State *s = new State();

    char line[32];
    while(input.getline(line, 32)) {
        s->process_line(line);
    }

    s->finished();

    return EXIT_SUCCESS;
}
