@javascript
Feature: Fulfil Orders
  In order to manage order statuses for shippable orders
  As an order fulfiller
  I need to be able to view "processing" orders and mark them as "completed"

  Background:
    Given orders:
      | qty | status     | name     | shipto |
      | 10  | processing | bobart   | us     |
      | 9   | processing | bilberto | intl   |
      | 8   | processing | tom      | us     |
      | 7   | processing | tomas    | intl   |
      #| 6   | completed  | bobart   | us     |
      #| 5   | pending    | tomas    | intl   |

  Scenario: View international orders with status "processing" (default view)
    Given I am logged in as a user with the "administrator" role
    And I go to "/admin/orders/fulfil_international"
    Then I should see 2 "td" elements

  Scenario: Mark orders as "completed"
    Given I am logged in as a user with the "administrator" role
    And I go to "/admin/orders/fulfil_international"
    When I check the box "views_bulk_operations[0]"
    And I select "rules_component::rules_commerce_order_status_completed" from "edit-operation"
    And I press "Apply"
    Then I should see 1 "tr" elements

  Scenario: View international orders with status "completed"
    Given I am logged in as a user with the "administrator" role
    And I go to "/admin/orders/fulfil_international"
    When I select "completed" from "edit-status"
    Then I should see 1 "tr" element

  Scenario: View domestic orders with status "processing" (default view)

