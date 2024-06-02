// Copyright 2024 Sota Horiguchi (@ImSota)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
//#define EE_HANDS
#define MASTER_RIGHT

//薙刀式設定用-------------------------------------------------------
#define NAGINATA_TATEGAKI
// #define NAGINATA_YOKOGAKI

#define NAGINATA_EDIT_WIN // JP106
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE

// #define NAGINATA_EDIT_MAC // US101
// Macはunicode入力を使わない
// #define MAC_LIVE_CONVERSION // Macでライブ変換をオンにしている場合

// #define NAGINATA_EDIT_LINUX
// #define UNICODE_SELECTED_MODES UC_LNX

// #define NAGINATA_KOUCHI_SHIFT // シフトを後置でも有効にする
//--------------------------------------------------------------------

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT