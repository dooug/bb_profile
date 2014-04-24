@api @javascript
Feature: Fulfil Orders
  In order to manage order statuses for shippable orders
  As an order fulfiller
  I need to be able to view "processing" orders and mark them as "completed"

  Background:
    Given orders:
      | qty | status     | name     | shipto |
      | 10  | processing | bobart   | us     |
      | 1   | processing | bilberto | intl   |
      | 8   | processing | tom      | us     |
      | 2   | processing | tomas    | intl   |
      #| 6   | completed  | bobart   | us     |
      #| 5   | pending    | tomas    | intl   |

  # International orders should only show orders going to non-US addresses from new customers with only one can in the shipment
  Scenario: View international orders with status "processing" (default view)
    Given I am logged in as a user with the "administrator" role
    And I go to "/admin/commerce/orders/fulfil_international"
    Then the "table.views-table" element should contain "bilberto"
    And the "table.views-table" element should not contain "tomas"
    And the "table.views-table" element should not contain "tom"
    And the "table.views-table" element should not contain "bobart"

  @api
  Scenario: Mark orders as "completed"
    Given I am logged in as a user with the "administrator" role
    And I go to "/admin/commerce/orders/fulfil_international"
# customs number / shipment ID: use editableviews or something like that?
    And I enter a random number in the "customs_id" input for the row that contains "Bilberto"
    And I focus on the next input
    Then I should see the status "completed" in the row that contains "Bilberto"

  Scenario: View international orders with status "completed"
    Given I am logged in as a user with the "administrator" role
    And I go to "/admin/commerce/orders/fulfil_international"
    When I select "completed" from "edit-status"
    Then I should see 1 "tr" element

  Scenario: View domestic orders with status "processing" (default view)

