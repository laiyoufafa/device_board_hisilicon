/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef HI3516_DAI_OPS_H
#define HI3516_DAI_OPS_H

#include "audio_core.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

int32_t Hi3516DaiDeviceInit(struct AudioCard *audioCard, const struct DaiDevice *dai);
int32_t Hi3516DaiStartup(const struct AudioCard *card, const struct DaiDevice *device);
int32_t Hi3516DaiHwParams(const struct AudioCard *card, const struct AudioPcmHwParams *param);
int32_t Hi3516DaiTrigger(const struct AudioCard *card, int cmd, const struct DaiDevice *device);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* HI3516_CODEC_OPS_H */