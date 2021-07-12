/**
  ******************************************************************************
  * @file    low_level_device.c
  * @author  MCD Application Team
  * @brief   This file contains device definition for low_level_device
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "region_defs.h"
#include "low_level_flash.h"
static struct flash_range access_vect[] =
{
  { FLASH_NV_COUNTERS_AREA_OFFSET, FLASH_NV_COUNTERS_AREA_OFFSET + FLASH_NV_COUNTER_AREA_SIZE - 1},
  { FLASH_SST_AREA_OFFSET, FLASH_SST_AREA_OFFSET + FLASH_SST_AREA_SIZE - 1},
  { FLASH_ITS_AREA_OFFSET, FLASH_ITS_AREA_OFFSET + FLASH_ITS_AREA_SIZE - 1},
};
#if defined(MCUBOOT_OVERWRITE_ONLY) || (MCUBOOT_IMAGE_NUMBER == 1)
#define write_vect access_vect
#else
static struct flash_range write_vect[] =
{
  { FLASH_NV_COUNTERS_AREA_OFFSET, FLASH_NV_COUNTERS_AREA_OFFSET + FLASH_NV_COUNTER_AREA_SIZE - 1},
  { FLASH_SST_AREA_OFFSET, FLASH_SST_AREA_OFFSET + FLASH_SST_AREA_SIZE - 1},
  { FLASH_ITS_AREA_OFFSET, FLASH_ITS_AREA_OFFSET + FLASH_ITS_AREA_SIZE - 1},
  /* Area for writing confirm flag on in installed image */
  { S_IMAGE_PRIMARY_PARTITION_OFFSET + FLASH_S_PARTITION_SIZE - 32, S_IMAGE_SECONDARY_PARTITION_OFFSET + FLASH_PARTITION_SIZE - 16 -1}
};
#endif /*defined(MCUBOOT_OVERWRITE_ONLY) || (MCUBOOT_IMAGE_NUMBER == 1) */
struct low_level_device FLASH0_DEV =
{
  .erase = { .nb = sizeof(access_vect) / sizeof(struct flash_range), .range = access_vect},
  .write = { .nb = sizeof(write_vect) / sizeof(struct flash_range), .range = write_vect},
};