<?php
/**
 * @file
 * bb_misc.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function bb_misc_default_rules_configuration() {
  $items = array();
  $items['commerce_tax_rate_sample_michigan_sales_tax'] = entity_import('rules_config', '{ "commerce_tax_rate_sample_michigan_sales_tax" : {
      "LABEL" : "Calculate Sample Michigan Sales Tax 6%",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_order", "commerce_tax" ],
      "USES VARIABLES" : { "commerce_line_item" : { "label" : "Line item", "type" : "commerce_line_item" } },
      "IF" : [
        { "commerce_order_compare_address" : {
            "commerce_order" : [ "commerce-line-item:order" ],
            "address_field" : "commerce_customer_shipping|commerce_customer_address",
            "address_component" : "administrative_area",
            "value" : "MI"
          }
        }
      ],
      "DO" : [
        { "commerce_tax_rate_apply" : {
            "USING" : {
              "commerce_line_item" : [ "commerce-line-item" ],
              "tax_rate_name" : "sample_michigan_sales_tax"
            },
            "PROVIDE" : { "applied_tax" : { "applied_tax" : "Applied tax" } }
          }
        }
      ]
    }
  }');
  return $items;
}
