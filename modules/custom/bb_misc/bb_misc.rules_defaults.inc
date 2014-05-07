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
  $items['commerce_checkout_intl_order_send_an_order_notification_email'] = entity_import('rules_config', '{ "commerce_checkout_intl_order_send_an_order_notification_email" : {
      "LABEL" : "International Order - Send an order notification email",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "commerce_order", "rules", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "NOT commerce_order_compare_address" : {
            "commerce_order" : [ "commerce_order" ],
            "address_field" : "commerce_customer_shipping|commerce_customer_address",
            "address_component" : "country",
            "value" : "US"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "commerce-order:mail" ],
            "subject" : "Order [commerce-order:order-number] at [site:name]",
            "message" : "Hi [commerce-order:commerce-customer-billing:commerce-customer-address:first_name], your order will ship today from our fulfillment partner is Hong Kong via Sinagpore Post. Your customs number is [commerce-order:field-customs-id] and you can follow it\\u2019s progress at this site: http:\\/\\/www.17track.net\\/en\\/result\\/post.shtml?nums=[commerce-order:field-customs-id]\\r\\nIt will take a few days for your parcel to enter the system so don\\u2019t be surprised when you don\\u2019t see anything pop up on there right now. Your package is shipping out on a boat, so it may sit in the port for several days or longer. After it leaves Hong Kong, there will be no further updates until it reaches [commerce-order:commerce-customer-billing:commerce-customer-address:country]. At that point, a phone call to your post office is the best way to get your packages cleared through customs and delivered.\\r\\nPlease keep me posted! International shipping is a complex task and I\\u2019m always happy to know when packages arrive safely and to troubleshoot problems.\\r\\n-Jon",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['commerce_checkout_order_email'] = entity_import('rules_config', '{ "commerce_checkout_order_email" : {
      "LABEL" : "Domestic Normal Order - Send an order notification e-mail",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "commerce_order", "rules", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "commerce_order_compare_address" : {
            "commerce_order" : [ "commerce_order" ],
            "address_field" : "commerce_customer_shipping|commerce_customer_address",
            "address_component" : "country",
            "value" : "US"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "commerce-order:mail" ],
            "subject" : "Order [commerce-order:order-number] at [site:name]",
            "message" : "Hi [commerce-order:commerce-customer-billing:commerce-customer-address:first_name], got you all packed up, will ship today!\\r\\n-Jon\\r\\n",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
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
  $items['rules_order_paid_in_full_order_state_to_processing'] = entity_import('rules_config', '{ "rules_order_paid_in_full_order_state_to_processing" : {
      "LABEL" : "Order paid in full: Order state to processing",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_cart", "commerce_order", "commerce_payment" ],
      "ON" : { "commerce_payment_order_paid_in_full" : [] },
      "IF" : [
        { "NOT commerce_order_is_cart" : { "commerce_order" : [ "commerce_order" ] } }
      ],
      "DO" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "processing" } }
      ]
    }
  }');
  $items['rules_update_the_order_status_on_checkout_completion_if_payment_'] = entity_import('rules_config', '{ "rules_update_the_order_status_on_checkout_completion_if_payment_" : {
      "LABEL" : "Update the order status on checkout completion (if payment complete)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "commerce_payment", "commerce_order", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "commerce_payment_order_balance_comparison" : { "commerce_order" : [ "commerce_order" ], "value" : "0" } }
      ],
      "DO" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "processing" } }
      ]
    }
  }');
  return $items;
}
