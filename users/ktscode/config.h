#pragma once

// Shared tuning for all ktscode boards. Dual-role keys (LCTL_T(KC_ESC),
// SFT_T(KC_ENT), ...) tuned for fast "swift tap" typing, per
// https://precondition.github.io/home-row-mods

// Below the 200ms default, so a quick hold registers the modifier sooner — fast
// Ctrl+A and tmux Ctrl+A H/L fire the mod instead of the tapped letter. Tune to
// taste: lower (140/130) if mods still miss, raise if normal typing misfires.
#define TAPPING_TERM 150

// A key tapped+released during the hold selects the modifier — helps fast rolls.
#define PERMISSIVE_HOLD

// Disable tap-then-hold auto-repeat, so a quick tap immediately followed by a
// hold of the same key acts as the modifier instead of repeating the tap.
#define QUICK_TAP_TERM 0
