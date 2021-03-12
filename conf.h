// Copyright (c) 2019 Rumen G.Bogdanovski
// All rights reserved.
//
// You can use this software under the terms of 'INDIGO Astronomy
// open-source license' (see LICENSE.md).
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHORS 'AS IS' AND ANY EXPRESS
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


#ifndef CONF_H
#define CONF_H

#include <indigo/indigo_bus.h>
#include "blobpreview.h"

#if defined(INDIGO_WINDOWS)
#define PATH_LEN 4096
#else
#define PATH_LEN PATH_MAX
#endif

#define PROPERTY_AREA_MIN_WIDTH 500
#define CAMERA_FRAME_MIN_WIDTH 390
#define PREVIEW_WIDTH 550

#define CONFIG_FILENAME "indigo_imager.conf"
#define AIN_GUIDER_LOG_NAME_FORMAT "ain_guiding_%s.log"
#define AIN_INDIGO_LOG_NAME_FORMAT "ain_indigo_%s.log"

typedef enum {
	STRETCH_NONE = 0,
	STRETCH_SLIGHT = 1,
	STRETCH_MODERATE = 2,
	STRETCH_NORMAL = 3,
	STRETCH_HARD = 4,
} preview_stretch;

typedef enum {
	SHOW_FWHM = 0,
	SHOW_HFD = 1,
} focuser_display_data;

typedef enum {
	SHOW_RA_DEC_DRIFT = 0,
	SHOW_RA_DEC_PULSE = 1,
	SHOW_X_Y_DRIFT = 2,
} guider_display_data;

typedef enum {
	AIN_ALERT_STATE = INDIGO_ALERT_STATE,
	AIN_WARNING_STATE = INDIGO_BUSY_STATE,
	AIN_OK_STATE = 100
} object_alt_state;

typedef struct {
	bool blobs_enabled;
	bool auto_connect;
	bool indigo_use_host_suffix;
	indigo_log_levels indigo_log_level;
	bool use_state_icons;
	bool use_system_locale;
	bool antialiasing_enabled;
	int focus_mode;
	preview_stretch preview_stretch_level;
	int guider_save_bandwidth;
	int guider_subframe;
	int focuser_subframe;
	preview_stretch guider_stretch_level;
	bool guider_antialiasing_enabled;
	focuser_display_data focuser_display;
	guider_display_data guider_display;
	bool guider_save_log;
	bool indigo_save_log;
	char unused[100];
} conf_t;

extern conf_t conf;
extern char config_path[PATH_LEN];

//#define USE_LCD

#endif // CONF_H
