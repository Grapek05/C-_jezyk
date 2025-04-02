#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M_PI 3.14159265358979323846
 

enum Shape {
    SHAPE_CIRCLE,
    SHAPE_SQUARE,
    SHAPE_INVALID
};


enum Oper {
    OPER_FROM_LENGTH,
    OPER_FROM_AREA,
    OPER_FROM_PERIMETER,
    OPER_INVALID
};


struct Result {
    double length;
    double area;
    double perimeter;
};


enum Shape parse_shape(const char *shape) {
    if (strcmp(shape, "circle") == 0) {
        return SHAPE_CIRCLE;
    } else if (strcmp(shape, "square") == 0) {
        return SHAPE_SQUARE;
    } else {
        return SHAPE_INVALID;
    }
}


enum Oper parse_operation(const char *operation) {
    if (strcmp(operation, "length") == 0) {
        return OPER_FROM_LENGTH;
    } else if (strcmp(operation, "area") == 0) {
        return OPER_FROM_AREA;
    } else if (strcmp(operation, "perimeter") == 0) {
        return OPER_FROM_PERIMETER;
    } else {
        return OPER_INVALID;
    }
}


void calculate(struct Result *result, enum Shape shape, enum Oper operation, double value) {
    if (value <= 0) {
        printf("Invalid input value!\n");
        exit(EXIT_FAILURE);
    }

    switch (shape) {
        case SHAPE_CIRCLE:
            if (operation == OPER_FROM_LENGTH) {
                result->length = value;
                result->area = M_PI * value * value;
                result->perimeter = 2 * M_PI * value;
            } else if (operation == OPER_FROM_AREA) {
                result->area = value;
                result->length = sqrt(value / M_PI);
                result->perimeter = 2 * M_PI * result->length;
            } else if (operation == OPER_FROM_PERIMETER) {
                result->perimeter = value;
                result->length = value / (2 * M_PI);
                result->area = M_PI * result->length * result->length;
            }
            break;

        case SHAPE_SQUARE:
            if (operation == OPER_FROM_LENGTH) {
                result->length = value;
                result->area = value * value;
                result->perimeter = 4 * value;
            } else if (operation == OPER_FROM_AREA) {
                result->area = value;
                result->length = sqrt(value);
                result->perimeter = 4 * result->length;
            } else if (operation == OPER_FROM_PERIMETER) {
                result->perimeter = value;
                result->length = value / 4;
                result->area = result->length * result->length;
            }
            break;

        default:
            printf("Invalid input shape!\n");
            exit(EXIT_FAILURE);
    }
}

void print(const struct Result *result) {
    printf("Length: %.3f\n", result->length);
    printf("Area: %.3f\n", result->area);
    printf("Perimeter: %.3f\n", result->perimeter);
}


int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Invalid number of arguments!\n");
        return EXIT_FAILURE;
    }

    enum Shape shape = parse_shape(argv[1]);
    if (shape == SHAPE_INVALID) {
        printf("Invalid input shape!\n");
        return EXIT_FAILURE;
    }

    enum Oper operation = parse_operation(argv[2]);
    if (operation == OPER_INVALID) {
        printf("Invalid input type!\n");
        return EXIT_FAILURE;
    }

    double value = atof(argv[3]);
    if (value <= 0) {
        printf("Invalid input value!\n");
        return EXIT_FAILURE;
    }

    struct Result result = {0};

    calculate(&result, shape, operation, value);
    print(&result);

    return EXIT_SUCCESS;
}
