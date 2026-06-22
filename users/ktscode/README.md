# KTSCode Keyboards

Shared QMK userspace for my three 4x12 ortho boards. The four base layers
(QWERTY, LOWER, RAISE, GAME) live here as `KTS_*` macros and are **identical on
every board**; only the hardware-control `ADJUST` layer differs per board.

Source: `users/ktscode/` (shared logic + layers) and
`keyboards/<board>/keymaps/ktscode/` (per-board `ADJUST` + hardware hooks).

## Boards

| Board | MCU | LEDs | Extras |
|---|---|---|---|
| Nyquist LM rev1 | STM32G431 (split) | rgb_matrix (per-key) | green default, RGB screensaver |
| Planck rev7 | STM32F303 | rgblight (9-LED "overglow") | encoder, audio, dip switch |
| Levinson rev2 | atmega32u4 (split) | rgblight + single-color backlight | — |

## Layer access

- **LOWER** / **RAISE** — hold (momentary).
- **ADJUST** — hold LOWER + RAISE together (tri-layer).
- **GAME** — toggle from ADJUST; **QWERTY** key (on RAISE/GAME) toggles back.
- `·` below = transparent / no-op.

## QWERTY

```text
Tab    Q      W      E      R      T    │  Y      U      I      O      P      Bspc
CtlEsc A      S      D      F      G    │  H      J      K      L      ;      '
Shift  Z      X      C      V      B    │  N      M      ,      .      /      SftEnt
CtlSft Esc    Alt    Gui    LOWER  Ctl\ │  Space  RAISE  Adj[   -      =      Alt]
```

- **CtlEsc** = Esc on tap, Ctrl on hold. **SftEnt** = Enter tap / Shift hold.
- **Ctl\\** = `\` tap / Ctrl hold. **Adj[** = `[` tap / ADJUST hold. **Alt]** = `]` tap / Alt hold.
- **CtlSft** = Ctrl+Shift. Tuned for fast typing via `TAPPING_TERM` + `PERMISSIVE_HOLD`.

## LOWER

```text
`      1      2      3      4      5    │  6      7      8      9      0      ·
·      F1     F2     F3     F4     F5   │  F6     4      5      6      .      *
·      F7     F8     F9     F10    F11  │  F12    1      2      3      /      ·
·      ·      ·      ·      ·      ·    │  0      ·      ·      ·      +      ·
```

Numbers, F-keys, and a right-hand numpad cluster.

## RAISE

```text
~      !      @      #      $      %    │  ^      &      *      (      )      Del
·      WhUp   Ms1    MsUp   Ms2    Qwrty│  ←      ↓      ↑      →      S(-)   \
·      WhDn   MsL    MsDn   MsR    S(=) │  -      =      [      ]      {      }
·      ·      ·      ·      ·      ·    │  Ins    ·      Home   PgDn   PgUp   GuiEnd
```

- Symbols, mouse keys (left half: **Ms1/Ms2** buttons, **MsUp/Dn/L/R** move, **WhUp/Dn** wheel), arrows, nav.
- **Qwrty** = back to QWERTY default layer. **GuiEnd** = End tap / Gui hold.

## GAME

```text
`      Esc    Q      W      E      R    │  T      Ms1    MsUp   Ms2    Y      Bspc
Shift  Tab    A      S      D      F    │  G      MsL    MsDn   MsR    L      Qwrty
I      Alt    Z      X      C      V    │  B      1      2      3      4      Enter
Alt    Ctrl   ↓      ↑      Ms2    Space│  Space  Shift  ←      PgUp   PgUp   →
```

Left side reshaped for gaming (dedicated mods, no mod-taps); mouse on the right. **Qwrty** exits.

## ADJUST (per board)

Hardware control. Same skeleton on each board; the RGB / audio / backlight keys
differ. Function labels: **Boot** = bootloader (DFU), **C-A-D** = Ctrl+Alt+Del,
**AGnrm** = un-swap Alt/Gui, **Light** = the BACKLIT key, **FX+/FX-** = cycle
RGB effect, **RGBtg** = RGB on/off.

### Nyquist LM rev1 — rgb_matrix

```text
Esc    ·      ·      ·      Boot   ·    │  ·      Hue+   Hue-   Spd+   Spd-   C-A-D
Caps   ·      ·      Sat+   Sat-   GAME │  ·      AGnrm  PrtSc  ScrLk  Pause  ·
·      Val+   Val-   ·      ·      Prev │  Next   Mute   Vol-   Vol+   ·      ·
Light  ·      ·      ·      ·      Play │  Play   ·      ·      FX+    FX-    RGBtg
```

- RGB: **Hue** U/I · **Sat** D/F · **Bright** Z/X · **Speed** O/P · **Effect** `-`/`=` · **Toggle** `]`.
- Default hue is green; effect auto-switches to Digital Rain after 60s idle, back to Solid on any key.
- Rainbow/cycle effects ignore hue — pick a solid effect first, then set Hue/Sat.

### Planck rev7 — rgblight + audio

```text
Esc    ·      ·      ·      Boot   ·    │  ·      Hue+   Hue-   Breath ·      C-A-D
Caps   ·      ·      AudOn  AudOff GAME │  ·      AGnrm  PrtSc  ScrLk  Pause  ·
·      Voic-  Voic+  MusOn  MusOff Prev │  Next   Mute   Vol-   Vol+   ·      ·
Light  ·      ·      ·      ·      Play │  Play   ·      BLtog  FX+    FX-    RGBtg
```

- **Breath** = breathing effect. **AudOn/Off**, **MusOn/Off**, **Voic-/+** = audio + music mode.
- Rotary encoder plays a pitch-bending tone; dip switch toggles ADJUST.

### Levinson rev2 — rgblight + backlight

```text
Esc    ·      ·      ·      Boot   ·    │  ·      Hue+   Hue-   Spd+   Spd-   C-A-D
Caps   ·      ·      Sat+   Sat-   GAME │  ·      AGnrm  PrtSc  ScrLk  Pause  ·
·      Val+   Val-   ·      ·      Prev │  Next   Mute   Vol-   Vol+   ·      ·
Light  ·      ·      ·      BLstp  Play │  Play   ·      BLtog  FX+    FX-    RGBtg
```

- **BLtog** / **BLstp** = backlight toggle / brightness step (single-color LED backlight).
- RGB keys drive the rgblight underglow (same positions as the Nyquist).

## Setup notes

How this userspace came together (newest first):

- **Mod-tap tuning** — `TAPPING_TERM` set to 110 ms with `PERMISSIVE_HOLD` and `QUICK_TAP_TERM 0` so fast Ctrl+A / tmux rolls register the modifier instead of the tapped letter ([precondition home-row-mods guide](https://precondition.github.io/home-row-mods)).
- **Nyquist RGB** — green default hue, plus a "screensaver": Digital Rain after 60 s idle, back to Solid on the next key (`housekeeping_task_user` in the keymap).
- **Dead-key fix** — a non-responsive LOWER key turned out to be a cold solder joint on the hotswap socket, found with `qmk console` matrix debug; the key's row and column both worked for other keys, isolating the fault to that one switch.
- **Core update** — merged `upstream/master` so the 2025 Nyquist LM (`keyboard.json`) builds; the previous core (QMK 0.21.3) predated that data-driven format.
- **Keycode modernization** (post-merge) — `RGB_*` → `RM_*` (rgb_matrix) / `UG_*` (rgblight), and `KC_MS_*`/`KC_BTN*`/`KC_WH_*` → `MS_*`.
- **Userspace** — extracted the four shared layers into `KTS_*` macros so all three boards stay in sync; each board keeps only its `ADJUST` + hardware hooks.

## Flashing

Split boards (Nyquist, Levinson) flash **each half separately** — plug that half in directly (not through the TRRS cable), put it in bootloader, flash, repeat. Same firmware goes on both halves; handedness is set by hardware.

| Board | Command |
|---|---|
| Nyquist LM | `qmk flash -kb keebio/nyquist_lm/rev1 -km ktscode` |
| Planck rev7 | `qmk flash -kb planck/rev7 -km ktscode` |
| Levinson rev2 | `qmk flash -kb keebio/levinson/rev2 -km ktscode` |

Enter the bootloader (any one):

- Hold **Lower+Raise**, press **Boot** (the `R` key on ADJUST = `QK_BOOT`).
- Press the PCB reset button (hold ~1 s on the STM32 boards).
- Bootmagic: hold the top-outer key of a half while plugging it in.

Notes:

- **STM32 (Nyquist, Planck)**: after `File downloaded successfully`, dfu-util prints `Error during download get_status` / `Error 74`. Harmless — the chip resets before dfu-util can read status; the flash already succeeded.
- **Levinson (AVR)**: caterina bootloader, double-tap reset.

## Committing & pushing

```sh
git add -A
git commit -m "Describe the change"
git push                 # first push of this branch: git push -u origin KTSCode
```

Keep commits focused, and don't force-push the shared branch.
