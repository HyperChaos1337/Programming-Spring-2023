#ifndef COURSE_WORK_2_CELL_H
#define COURSE_WORK_2_CELL_H

class Cell{
private:
    int size = 32;
public:
    Cell() = default;
    explicit Cell(int size);
    void set_size(int cell_size);
    int get_size() const;
};

#endif