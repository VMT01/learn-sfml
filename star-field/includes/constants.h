#pragma once

#define WINDOW_WIDTH        400.0f
#define WINDOW_HEIGHT       400.0f
#define WINDOW_TITLE        "Star Field"     
#define ANTI_ALIASING_LEVEL 8

#define MAX_POINT_NUMBER    200

#define ZOOM_SIZE           2.0f
#define ZOOM_STEP           0.03f
#define X_JUMP_STEP         (WINDOW_WIDTH / 2.0f) * (ZOOM_STEP / ZOOM_SIZE)
#define Y_JUMP_STEP         (WINDOW_HEIGHT / 2.0f) * (ZOOM_STEP / ZOOM_SIZE)