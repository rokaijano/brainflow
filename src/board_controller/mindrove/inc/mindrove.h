
#pragma once

#include <thread>

#include "board.h"
#include "board_controller.h"


class MindRove : public Board
{

private:
    volatile bool keep_alive;
    bool initialized;
    bool is_streaming;
    std::thread streaming_thread;

    void read_thread ();

public:
    MindRove (struct BrainFlowInputParams params);
    ~MindRove ();

    int prepare_session ();
    int start_stream (int buffer_size, char *streamer_params);
    int stop_stream ();
    int release_session ();
    int config_board (char *config);

    static constexpr int package_size = 30;
};