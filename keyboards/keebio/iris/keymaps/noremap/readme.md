# noremap — Keebio Iris Rev.5 Keymap

> **Keyboard:** Keebio Iris Rev.5 (underglow RGB, not per-key RGB)  
> **Base layout:** Dvorak  
> **Flashing:** `qmk flash -kb keebio/iris/rev5 -km noremap`

---

## Physical layout

The Iris Rev.5 is a 56-key split ergo with a 6-column + 3-thumb layout.

```
┌────┬────┬────┬────┬────┬────┐         ┌────┬────┬────┬────┬────┬────┐
│ 00 │ 01 │ 02 │ 03 │ 04 │ 05 │         │ 05 │ 04 │ 03 │ 02 │ 01 │ 00 │  ← row 0
├────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼────┤
│ 10 │ 11 │ 12 │ 13 │ 14 │ 15 │         │ 15 │ 14 │ 13 │ 12 │ 11 │ 10 │  ← row 1
├────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼────┤
│ 20 │ 21 │ 22 │ 23 │ 24 │ 25 │         │ 25 │ 24 │ 23 │ 22 │ 21 │ 20 │  ← row 2
├────┼────┼────┼────┼────┼────┼────┬────┼────┼────┼────┼────┼────┼────┤
│ 30 │ 31 │ 32 │ 33 │ 34 │ 35 │ I1 │ I2 │ 35 │ 34 │ 33 │ 32 │ 31 │ 30 │  ← row 3
└────┴────┴────┴────┼────┼────┼────┼────┼────┼────┼────┴────┴────┴────┘
                    │ T1 │ T2 │ T3 │ T3 │ T2 │ T1 │                    ← thumbs
                    └────┴────┴────┴────┴────┴────┘
```

**Matrix notes for QMK edits:**
- Row 3 has 14 keys: left 6 → inner-left → inner-right → right 6 (the right 6 are reversed in the `LAYOUT()` macro)
- Thumb row has 3 keys per side: left `[4,2] [4,3] [4,4]`, right `[9,4] [9,3] [9,2]` (also reversed on the right)

---

## Layer overview

| Layer | How to access | Purpose |
|-------|---------------|---------|
| **Base** | Default | Dvorak typing, Hyper-Tab, Game toggle |
| **Raise** | Hold either inner thumb (`Space` position) | Navigation with Dvorak mnemonics |
| **Lower** | Hold right outer key | Numpad, media, F-keys, RGB underglow |
| **Game** | Tap `Ct/Gm` (base right pinky) | QWERTY gaming layer |
| **Adjust** | Hold **Lower + Raise** simultaneously | Boot, RGB fine-tuning |

---

## Base layer — Dvorak

```
┌─────┬────┬────┬────┬────┬────┐         ┌────┬────┬────┬────┬────┬─────┐
│Esc~ │ 1  │ 2  │ 3  │ 4  │ 5  │         │ 6  │ 7  │ 8  │ 9  │ 0  │ Bsp │
├─────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼─────┤
│Hyper│ '  │ ,  │ .  │ P  │ Y  │         │ F  │ G  │ C  │ R  │ L  │  /  │
│/Tab │    │    │    │    │    │         │    │    │    │    │    │     │
├─────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼─────┤
│ Ctl │ A  │ O  │ E  │ U  │ I  │         │ D  │ H  │ T  │ N  │ S  │Ct/Gm│
├─────┼────┼────┼────┼────┼────┼────┬────┼────┼────┼────┼────┼────┼─────┤
│ Sft │ ;  │ Q  │ J  │ K  │ X  │Bspc│Ent │ B  │ M  │ W  │ V  │ Z  │S+Ent│
└─────┴────┴────┴────┼────┼────┼────┼────┼────┼────┼────┴────┴────┴─────┘
                     │Alt │Gui │Rse │Rse │Gui │Lwr │
                     └────┴────┴────┴────┴────┴────┘
```

**Thumb behavior:**
- **Both inners** (`Rse`) = tap `Space`, hold `Raise`
- **Right outer** (`Lwr`) = momentary `Lower` (no tap function)

**Inner keys:**
- `Ent` = **right** inner (right thumb) — so `Shift` (left pinky) + `Ent` is cross-hand
- `Bspc` = **left** inner (left thumb)
- `S+Ent` = **right outer pinky** = `S(KC_ENT)` — one key that sends `Shift+Enter` as a chord

**Special keys:**
- `Hyper/Tab` = `LCAG_T(KC_TAB)` — tap for Tab, hold for Ctrl+Alt+Cmd
- `Game` = tap to enter Game layer
- `Ct/Gm` = `RCTL_T(GAME)` — hold for right `Ctrl` (makes `Ctrl+A/E/U/K/W/R`
  cross-hand), tap for Game layer
- `Esc~` = `QK_GESC` — tap for Esc, Shift+tap for `~`
- `S+Ent` = `S(KC_ENT)` — one key that sends `Shift+Enter` (was `AltGr`)

---

## Raise layer — Navigation + Symbols

```
┌─────┬────┬────┬────┬────┬────┐         ┌────┬────┬────┬────┬────┬─────┐
│ ~   │ !  │ @  │ #  │ $  │ %  │         │ ^  │ &  │ *  │ (  │ )  │ Del │
├─────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼─────┤
│ `   │ [  │ ]  │ {  │ }  │ \  │         │Home│End │PgUp│PgDn│Ins │     │
├─────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼─────┤
│     │Ent │ -  │ =  │PgDn│Home│         │Home│PgDn│ =  │ -  │ Del│     │
├─────┼────┼────┼────┼────┼────┼────┬────┼────┼────┼────┼────┼────┼─────┤
│ Sft │ ←  │ ↓  │ ↑  │ →  │End │Bspc│Ent │ ←  │ ↓  │ ↑  │ →  │End │     │
└─────┴────┴────┴────┼────┼────┼────┼────┼────┼────┼────┴────┴────┴─────┘
                     │    │    │    │    │    │    │
                     └────┴────┴────┴────┴────┴────┘
```

**Arrows — bottom row of BOTH halves, read the same left-to-right:**
- Left  (`; Q J K X`) = `← ↓ ↑ → End`
- Right (`B M W V Z`) = `← ↓ ↑ → End`
- Same order on both halves: leftmost = Left, then Down, Up, Right, End on
  the innermost key
- This restores the original left-hand positions (`← ↓ ↑ →` on `; Q J K`,
`End` on `X`); the previous build had slid them one column right.

**- / = — home row of BOTH halves, under the resting ring/middle fingers:**
- Left  (`A O E U I`) = `Ent - = PgDn Home`
- Right (`D H T N S`) = `Home PgDn = - Del`
- `-` / `_` = `KC_MINS`, `=` / `+` = `KC_EQL`, in the same finger slot on each hand
- Brackets `[ ] { }` stay on the left top row; page nav (`Home/End/PgUp/PgDn/Ins`)
stays on the right top row

**Inner thumbs mirror Base:** left inner `Bspc`, right inner `Ent`.

**Why this works:**
- The nav layer now reads the same from either hand: arrows on the bottom,
symbols on the home row, page nav on the top
- `-` / `=` are directly under the fingers that rest on `O E` / `N T`
- Enter is one thumb away on the right, so `Shift + Enter` is cross-hand;
`S+Ent` also fires `Shift+Enter` as a single chord

---

## Lower layer — Numpad, media, F-keys

```
┌─────┬────┬────┬────┬────┬────┐         ┌────┬────┬────┬────┬────┬─────┐
│ F12 │ F1 │ F2 │ F3 │ F4 │ F5 │         │ F6 │ F7 │ F8 │ F9 │ F10│ F11 │
├─────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼─────┤
│RGB T│RGB+│Hue+│Hue-│Pst │Ynk │         │ 7  │ 8  │ 9  │ /  │ *  │     │
├─────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼─────┤
│Play │Next│Prev│Vol+│Vol-│Mute│         │ 4  │ 5  │ 6  │ -  │ +  │     │
├─────┼────┼────┼────┼────┼────┼────┬────┼────┼────┼────┼────┼────┼─────┤
│     │    │    │    │    │    │    │    │ 1  │ 2  │ 3  │Ent │ 0  │ .   │
└─────┴────┴────┴────┼────┼────┼────┼────┼────┼────┼────┴────┴────┴─────┘
                     │    │    │    │    │    │    │
                     └────┴────┴────┴────┴────┴────┘
```

**Right hand numpad** is a standard calculator block — `7-8-9` / `4-5-6` / `1-2-3` / `0-.` — universally familiar.  
**Left hand** = media cluster + RGB underglow controls (`UG_TOGG`, `UG_NEXT`, `UG_HUEU/D`).

**Left top row = clipboard** (Linux terminal), vim-mnemonic:
- `P` (put) = `Ctrl+Shift+V` (paste)
- `Y` (yank) = `Ctrl+Shift+C` (copy)
- On macOS just use base `Cmd+C` / `Cmd+V`. Firmware can't detect the OS, so
  the OS-specific chord lives on the layer.
- The readline chords are **not** on a layer: use right `Ctrl` + the letter
  on base (`Ctrl+A/E/U/K/W/R/L`), which is the mnemonic itself.

---

## Game layer — QWERTY

```
┌─────┬────┬────┬────┬────┬────┐         ┌────┬────┬────┬────┬────┬─────┐
│Esc~ │ 1  │ 2  │ 3  │ 4  │ 5  │         │ 6  │ 7  │ 8  │ 9  │ 0  │ Bsp │
├─────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼─────┤
│ Tab │ Q  │ W  │ E  │ R  │ T  │         │ Y  │ U  │ I  │ O  │ P  │     │
├─────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼─────┤
│ Ctl │ A  │ S  │ D  │ F  │ G  │         │ H  │ J  │ K  │ L  │    │Exit │
├─────┼────┼────┼────┼────┼────┼────┬────┼────┼────┼────┼────┼────┼─────┤
│ Sft │ Z  │ X  │ C  │ V  │ B  │Spc │Ent │ N  │ M  │ ,  │ .  │ /  │     │
└─────┴────┴────┴────┼────┼────┼────┼────┼────┼────┼────┴────┴────┴─────┘
                     │Alt │Gui │Spc │Ent │Gui │Lwr │
                     └────┴────┴────┴────┴────┴────┘
```

- Plain `Space` and `Enter` on thumbs — no layer-taps for gaming
- `Exit` (`EXT_GM`) on right pinky to return to Base
- `QK_GESC` at top-left (Shift+Esc = `~`)

---

## Adjust layer — System & RGB

Accessed by **holding Lower + Raise simultaneously** (right outer + either inner thumb).

```
┌─────┬────┬────┬────┬────┬────┐         ┌────┬────┬────┬────┬────┬─────┐
│Boot │    │    │    │    │    │         │    │    │    │    │    │     │
├─────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼─────┤
│RGB T│RGB+│H+  │H-  │S+  │S-  │         │V+  │V-  │Sp+ │Sp- │    │     │
├─────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼─────┤
│     │    │    │    │    │    │         │    │    │    │    │    │     │
├─────┼────┼────┼────┼────┼────┼────┬────┼────┼────┼────┼────┼────┼─────┤
│     │    │    │    │    │    │    │    │    │    │    │    │    │     │
└─────┴────┴────┴────┼────┼────┼────┼────┼────┼────┼────┴────┴────┴─────┘
                     │    │    │    │    │    │    │
                     └────┴────┴────┴────┴────┴────┘
```

- `Boot` = `QK_BOOT` — enter bootloader for flashing (no reset button needed)
- `RGB T` = `UG_TOGG` — toggle underglow on/off
- `H+/-` = hue, `S+/-` = saturation, `V+/-` = brightness/value, `Sp+/-` = animation speed

---

## Keycode quick reference

### Mod-taps (hold for mod, tap for key)
```c
LCTL_T(KC_A)    // hold Ctrl, tap A
LSFT_T(KC_SCLN) // hold Shift, tap ;
LALT_T(KC_Q)    // hold Alt, tap Q
LGUI_T(KC_J)    // hold Gui/Cmd, tap J
// Combos: LSFT, RSFT, LCTL, RCTL, LALT, RALT, LGUI, RGUI, LCAG (Ctrl+Alt+Gui), MEH (Ctrl+Alt+Shift), HYPR (all)
// Modified keys in a keymap: S(KC_ENT) = Shift+Enter, C(KC_A) = Ctrl+A, etc.
```

### Layer-taps (hold for layer, tap for key)
```c
LT(_RAISE, KC_SPC)  // hold Raise layer, tap Space
// Warning: these can conflict with home-row mods if both fire
```

### RGB Underglow (Iris Rev.5)
```c
UG_TOGG  // toggle on/off
UG_NEXT  // next animation mode
UG_HUEU  // hue up
UG_HUED  // hue down
UG_SATU  // saturation up
UG_SATD  // saturation down
UG_VALU  // value/brightness up
UG_VALD  // value/brightness down
UG_SPDU  // speed up
UG_SPDD  // speed down
```

### Grave Escape
```c
QK_GESC  // tap = Esc, Shift+tap = ~, Gui+tap = `
```

### Boot / Reset
```c
QK_BOOT  // enter bootloader for flashing
EE_CLR   // clear EEPROM (reset all settings)
```

### Transparent / no-op
```c
KC_TRNS  // pass through to lower layer (transparent)
KC_NO    // do nothing
XXXXXXX  // alias for KC_NO
```

---

## How to modify this keymap

### 1. Edit the layout
Open `keymap.c` and modify the `keymaps[]` array. Each `LAYOUT()` call is one layer.

**Critical:** The key order in `LAYOUT()` must match the physical wiring. For the Iris:
- Rows 0–2: left 6 keys left-to-right, then right 6 keys **right-to-left**
- Row 3: left 6 keys, then inner-left, then inner-right, then right 6 keys **right-to-left**
- Thumbs: left 3 keys left-to-right, then right 3 keys **right-to-left**

### 2. Add a new layer
1. Add an entry to the `enum custom_layers` block
2. Add a new `LAYOUT()` block in `keymaps[]`
3. Bind a key to access it (e.g. `MO(_NEWLAYER)`, `TG(_NEWLAYER)`, or `LT(_NEWLAYER, KC_SPC)`)

### 3. Enable/disable features
Edit `rules.mk`:
```makefile
# Example toggles
LTO_ENABLE = yes        # link-time optimization (saves space, keep this)
MOUSEKEY_ENABLE = no    # mouse keys (disable to save flash)
RGBLIGHT_ENABLE = yes   # underglow (keep this for rev5)
```

### 4. Change RGB behavior
Edit `config.h`:
```c
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP       // turn off LEDs when host sleeps
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
#define RGBLIGHT_DEFAULT_HUE  128
#define RGBLIGHT_DEFAULT_SAT  255
#define RGBLIGHT_DEFAULT_VAL  128
#endif
```

### 5. Common QMK features to consider

| Feature | Enable in `rules.mk` | What it does |
|---------|---------------------|--------------|
| Caps Word | `CAPS_WORD_ENABLE = yes` | Double-tap Shift = caps lock for one word only |
| Combos | `COMBO_ENABLE = yes` | Chord two keys to emit a third (e.g. `Q+W` = `Esc`) |
| Tap Dance | `TAP_DANCE_ENABLE = yes` | Different actions for 1x/2x/3x tap |
| Leader | `LEADER_ENABLE = yes` | Key sequences for macros |
| Auto Shift | `AUTO_SHIFT_ENABLE = yes` | Hold any key briefly to Shift it |

---

## Tips for split-ergo layouts

- **Thumbs are prime real estate.** Don't make both thumbs do the same thing. Space/Enter on the inners, modifiers or layer-toggles on the outers is the gold standard.
- **Put navigation on the hand that isn't holding modifiers.** If you use Ctrl/Cmd shortcuts while arrowing, keep arrows on the same hand as the modifiers for easy chording, or separate them if you prefer.
- **Duplicate Enter/Backspace on multiple layers.** These are your most frequent non-alpha keys; make them reachable everywhere.
- **Avoid nested layer-taps.** A `LT(layer, MT(mod, key))` will misfire constantly. Keep it simple: one tap/hold behavior per key.
- **Use `KC_TRNS` (transparent) generously.** If a layer is mostly the same as Base (e.g. Game layer), let the base keys pass through instead of redefining them.
- **Test changes incrementally.** QMK compiles fast. Change 3–4 keys at a time, flash, test, repeat.

---

## Flashing

```bash
# Compile only
qmk compile -kb keebio/iris/rev5 -km noremap

# Compile + flash (requires board in bootloader)
qmk flash -kb keebio/iris/rev5 -km noremap

# Or flash the .hex directly with QMK Toolbox / dfu-programmer / avrdude
# .hex is copied to: qmk_firmware/keebio_iris_rev5_noremap.hex
```

To enter bootloader:
1. **Software:** Use `QK_BOOT` from the Adjust layer (Lower + Raise)
2. **Hardware:** Press the reset button on the PCB (or short RST to GND)

---

## Last modified

- 2025 — refactored for Iris Rev.5 (was incorrectly targeting rev6)
- Feedback pass: Enter moved to right inner (cross-hand Shift+Enter), arrows
  unified on the bottom row of both halves in the same left-to-right order,
  `-`/`=` moved to the home row of both halves, right outer (ex-AltGr) is now
  `S(KC_ENT)` (Shift+Enter chord)
- Right pinky `RCTL_T(GAME)` (right Ctrl / Game) so readline chords are
  right `Ctrl` + letter; Lower's `P`/`Y` send Linux `Ctrl+Shift+V/C`
  (vim put/yank)
