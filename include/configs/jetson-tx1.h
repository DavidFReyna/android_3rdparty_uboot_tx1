/*
 * (C) Copyright 2013-2016
 * NVIDIA Corporation <www.nvidia.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef _P2371_2180_H
#define _P2371_2180_H

#include <linux/sizes.h>

#include "tegra210-common.h"

/* Parse the board ID EEPROM and update DT */
#define CONFIG_NV_BOARD_ID_EEPROM
#define CONFIG_OF_ADD_CHOSEN_MAC_ADDRS
#define CONFIG_OF_ADD_PLUGIN_MANAGER_IDS
#define EEPROM_I2C_BUS		3
#define EEPROM_I2C_ADDRESS	0x50

#define CONFIG_OF_ADD_CAM_BOARD_ID
#define CAM_EEPROM_I2C_BUS	5
#define CAM_EEPROM_I2C_ADDR	0x54

/* High-level configuration options */
#define CONFIG_SYS_PROMPT		"Tegra210 (P2371-2180) # "
#define CONFIG_TEGRA_BOARD_STRING	"NVIDIA P2371-2180"

/* Board-specific serial config */
#define CONFIG_TEGRA_ENABLE_UARTA

/* I2C */
#define CONFIG_SYS_I2C_TEGRA
#define CONFIG_CMD_I2C
#define CONFIG_SYS_VI_I2C_TEGRA

/* SD/MMC */
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_TEGRA_MMC
#define CONFIG_CMD_MMC

/* Enable gpt partition table */
#define CONFIG_PARTITION_UUIDS
#define CONFIG_RANDOM_UUID
#define CONFIG_CMD_UUID
#define CONFIG_CMD_GPT
#define CONFIG_EFI_PARTITION
#define CONFIG_FS_EXT4
#define CONFIG_CMD_FS_GENERIC

/* Environment in eMMC, at the end of 2nd "boot sector" */
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV		0
#define CONFIG_SYS_MMC_ENV_PART		2
#define CONFIG_ENV_OFFSET		(-CONFIG_ENV_SIZE)

/* SPI */
#define CONFIG_TEGRA114_SPI		/* Compatible w/ Tegra114 SPI */
#define CONFIG_TEGRA114_SPI_CTRLS	6
#define CONFIG_SPI_FLASH_WINBOND
#define CONFIG_SF_DEFAULT_MODE		SPI_MODE_0
#define CONFIG_SF_DEFAULT_SPEED		24000000
#define CONFIG_CMD_SPI
#define CONFIG_CMD_SF
#define CONFIG_SPI_FLASH_SIZE		(4 << 20)

/* USB2.0 Host support */
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_TEGRA
#define CONFIG_USB_MAX_CONTROLLER_COUNT	1
#define CONFIG_USB_STORAGE
#define CONFIG_CMD_USB

/* USB networking support */
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_ASIX

/* PCI host support */
#define CONFIG_PCI
#define CONFIG_PCI_TEGRA
#define CONFIG_PCI_PNP
#define CONFIG_CMD_PCI
#define CONFIG_CMD_PCI_ENUM

/* PCI networking support */
#define CONFIG_RTL8169

/* General networking support */
#define CONFIG_CMD_DHCP

/* Android fastboot support */
#define CONFIG_CMD_FASTBOOT
#define CONFIG_FASTBOOT_FLASH
#define CONFIG_FASTBOOT_GPT_NAME	0
#define CONFIG_FASTBOOT_FLASH_MMC_DEV	0
#define CONFIG_USB_FASTBOOT_BUF_SIZE	  0x40000000

/* Android bootimg support */
#define CONFIG_ANDROID_BOOT_IMAGE
#define CONFIG_USB_FASTBOOT_BUF_ADDR	  (NV_PA_SDRAM_BASE + 0x10000000)
#define CONFIG_CMD_BOOTA
#define CONFIG_CMD_BOOTA_BOOT_PART	      "LNX"
#define CONFIG_CMD_BOOTA_RECOVERY_PART	  "SOS"
#define CONFIG_CMD_BOOTA_DT_PART	      "DTB"
#define CONFIG_ANDROID_DT_HDR_BUFF	      (NV_PA_SDRAM_BASE + 0x03000000)
#define CONFIG_ANDROID_BOOT_HDR_BUFF	  (NV_PA_SDRAM_BASE + 0x04000000)
#define BOARD_EXTRA_ENV_SETTINGS \
	"fastboot_partition_alias_bootloader=bootloader\0" \
	"fastboot_partition_alias_boot=LNX\0" \
	"fastboot_partition_alias_dtb=DTB\0" \
	"fastboot_partition_alias_recovery=SOS\0" \
	"fastboot_partition_alias_system=APP\0" \
	"fastboot_partition_alias_cache=CAC\0" \
	"fastboot_partition_alias_misc=MSC\0" \
	"fastboot_partition_alias_factory=FCT\0" \
	"fastboot_partition_alias_userdata=UDA\0" \
	"fastboot_partition_alias_vendor=VNR\0" \
	"bootargs_append=" \
	"init=init fbcon=map:0 console=tty0 console=ttyS0,115200n8 androidboot.modem=none " \
	"androidboot.serialno=P2180A00P00940c003fd androidboot.security=non-secure tegraid=21.1.2.0.0 " \
	"ddr_die=2048M@2048M ddr_die=2048M@4096M section=256M memtype=0 usb_port_owner_info=0 lane_owner_info=0 " \
	"emc_max_dvfs=0 touch_id=0@63 video=tegrafb no_console_suspend=1 debug_uartport=lsport,0 " \
	"earlyprintk=uart8250-32bit,0x70006000 maxcpus=4 usbcore.old_scheme_first=1 lp0_vec=${lp0_vec} " \
	"nvdumper_reserved=${nvdumper_reserved} core_edp_mv=1125 core_edp_ma=4000 gpt android.kerneltype=normal " \
	"androidboot.touch_vendor_id=0 androidboot.touch_panel_id=63 androidboot.touch_feature=0 " \
	"androidboot.bootreason=pmc:software_reset,pmic:0x0 net.ifnames=0 \0"

#include "tegra-common-usb-gadget.h"
#include "tegra-common-post.h"

#define COUNTER_FREQUENCY	38400000

#endif /* _P2371_2180_H */
