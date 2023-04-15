#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


bool isSubrange(int r1s, int r1e, int r2s, int r2e) {
    return (r1s <= r2s && r1e >= r2e) || (r1s >= r2s && r1e <= r2e);
}


bool areOverlapping(int r1s, int r1e, int r2s, int r2e) {
    return (r1s <= r2e) && (r1e >= r2s);
}

class State {
    private:
      int m_subRanges = 0;

    public:
      void process_line(const char* line) {
        printf("%s\n", line);
        uint32_t range1Start, range1End, range2Start, range2End;

        if (sscanf(line, "%u-%u,%u-%u", &range1Start, &range1End, &range2Start, &range2End) != 4) {
            fprintf(stderr, "error readingin line %s\n", line);
            exit(EXIT_FAILURE);
        } else {
            if (areOverlapping(range1Start, range1End, range2Start, range2End)) {
                m_subRanges++;
            }
        }
      }

      void finished() {
        printf("subranges: %d\n", m_subRanges);
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
