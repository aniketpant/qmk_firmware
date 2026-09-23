#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _GAME,
  _ADJUST
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  GAME,
  EXT_GM,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base — Dvorak
   * Both inner thumbs = Raise/Space (symmetric)
   * Right outer = Lower
   * Enter = RIGHT inner (right thumb) so Shift (left pinky) + Enter is
   *   cross-hand; Backspace = LEFT inner (left thumb).
   * Right outer (was AltGr) = S(KC_ENT): one key that sends Shift+Enter
   *   as a chord.
   * Right pinky (row 2) = RCTL_T(GAME): hold = right Ctrl (makes the
   *   readline Ctrl+A/E/U/K/W/R chords cross-hand), tap = Game layer.
   */
  [_BASE] = LAYOUT(
    QK_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    LCAG_T(KC_TAB), KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
    KC_LCTL,        KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    RCTL_T(GAME),
    KC_LSFT,        KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_BSPC, KC_ENT,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    S(KC_ENT),
    KC_LALT,        KC_LGUI, LT(_RAISE,KC_SPC), LT(_RAISE,KC_SPC), KC_RGUI, LOWER
  ),

  /* Raise — Navigation + Symbols
   *
   * Arrows live on the BOTTOM row of BOTH halves and read the same way
   * left-to-right, so the pattern is literally identical on each hand:
   *   Left  (; Q J K X) = Left Down Up Right End
   *   Right (B M W V Z) = Left Down Up Right End
   *
   * - / = live on the HOME row of BOTH halves, under the ring/middle
   * fingers that rest there:
   *   Left  (A O E U I) = Ent - = PgDn Home
   *   Right (D H T N S) = Home PgDn = - Del
   *
   * Inner thumbs mirror Base: left inner = Bspc, right inner = Ent.
   * Top-left = brackets, top-right = page nav, Row0 = shifted numbers.
   */
  [_RAISE] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_GRV,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_INS,  KC_NO,
    KC_NO,   KC_ENT,  KC_MINS, KC_EQL,  KC_PGDN, KC_HOME, KC_HOME, KC_PGDN, KC_EQL,  KC_MINS, KC_DEL,  KC_NO,
    KC_LSFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  KC_BSPC, KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  /* Lower — Numpad + Media (right hand biased)
   *
   * Right hand = proper numpad block on home/bottom rows
   *   7 8 9  on F G C  (top row right)
   *   4 5 6  on D H T  (home row right)
   *   1 2 3  on B M W  (bottom row right)
   *   0 .    on V Z    (bottom row right, outer)
   *
   * Left hand = media + RGB underglow
   *   ' , .  = RGB controls
   *   P Y    = media
   *   A O E  = volume + playback
   *
   * Left top row = clipboard (Linux terminal chords), vim mnemonic:
   *   P (put)  = Ctrl+Shift+V (paste)
   *   Y (yank) = Ctrl+Shift+C (copy)
   * On macOS just use base Cmd+C / Cmd+V. The readline chords
   * (Ctrl+A/E/U/K/W/R/L) are right Ctrl + that letter on base.
   */
  [_LOWER] = LAYOUT(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, LCTL(LSFT(KC_V)), LCTL(LSFT(KC_C)), KC_P7, KC_P8, KC_P9, KC_PSLS, KC_PAST, KC_NO,
    KC_MPLY, KC_MNXT, KC_MPRV, KC_VOLU, KC_VOLD, KC_MUTE, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_PPLS, KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PENT, KC_P0, KC_PDOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  /* Game — QWERTY with plain thumbs
   * No layer-taps on thumbs (no accidental switches mid-fight)
   * Space and Enter are pure typing keys
   * EXT_GM exits back to Base
   */
  [_GAME] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_NO,   EXT_GM,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,  KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
    KC_LALT, KC_LGUI, KC_SPC,  KC_ENT,  KC_RGUI, LOWER
  ),

  /* Adjust — Hold Lower + Raise simultaneously
   * Bootloader + RGB fine-tuning
   */
  [_ADJUST] = LAYOUT(
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, UG_SPDU, UG_SPDD, KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case GAME:
            if (record->event.pressed) {
                layer_on(_GAME);
            }
            return false;
        case EXT_GM:
            if (record->event.pressed) {
                layer_off(_GAME);
            }
            return false;
    }
    return true;
}
