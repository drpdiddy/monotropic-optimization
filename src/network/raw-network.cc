#pragma once


struct RawNetwork {
struct Interval {
    double start;
    double end;
};

typedef int Node;

struct NetworkNode {
    double cost;
    Interval interval;
};

struct NetworkArc {
    Node initial_node;
    Node terminal_node;
    double cost;
    Interval interval;
};
};