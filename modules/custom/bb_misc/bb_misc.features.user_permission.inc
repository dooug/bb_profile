<?php
/**
 * @file
 * bb_misc.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bb_misc_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit any field_customs_id'.
  $permissions['edit any field_customs_id'] = array(
    'name' => 'edit any field_customs_id',
    'roles' => array(
      'administrator' => 'administrator',
      'international fulfiller' => 'international fulfiller',
    ),
    'module' => 'bb_misc',
  );

  // Exported permission: 'edit own field_customs_id'.
  $permissions['edit own field_customs_id'] = array(
    'name' => 'edit own field_customs_id',
    'roles' => array(),
    'module' => 'bb_misc',
  );

  // Exported permission: 'view any field_customs_id'.
  $permissions['view any field_customs_id'] = array(
    'name' => 'view any field_customs_id',
    'roles' => array(
      'administrator' => 'administrator',
      'international fulfiller' => 'international fulfiller',
    ),
    'module' => 'bb_misc',
  );

  // Exported permission: 'view own field_customs_id'.
  $permissions['view own field_customs_id'] = array(
    'name' => 'view own field_customs_id',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bb_misc',
  );

  return $permissions;
}
