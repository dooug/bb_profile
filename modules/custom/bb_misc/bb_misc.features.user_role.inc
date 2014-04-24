<?php
/**
 * @file
 * bb_misc.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function bb_misc_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: domestic fulfiller.
  $roles['domestic fulfiller'] = array(
    'name' => 'domestic fulfiller',
    'weight' => 4,
  );

  // Exported role: fulfiller.
  $roles['fulfiller'] = array(
    'name' => 'fulfiller',
    'weight' => 3,
  );

  // Exported role: international fulfiller.
  $roles['international fulfiller'] = array(
    'name' => 'international fulfiller',
    'weight' => 5,
  );

  return $roles;
}
