@api
Feature: Fulfil Orders
  In order to manage order statuses for shippable orders
  As an order fulfiller
  I need to be able to view "processing" orders and mark them as "completed"

  Background:
    Given customers:
      | name     | status | shipping address | previous orders |
      | Bobart   | 1      | domestic         | 0               |
      | Bilberto | 1      | international    | 0               |
      | Tom      | 1      | domestic         | 1               |
      | Tomas    | 1      | international    | 1               |
    And orders:
      | qty | status     | customer |
      | 10  | processing | Bobart   |
      | 9   | processing | Bilberto |
      | 8   | processing | Tom      |
      | 7   | processing | Tomas    |
      | 6   | completed  | Bobart   |
      | 5   | pending    | Tomas    |

  Scenario: View international orders with status "processing" (default view)
    Given I am at "/admin/orders/fulfil_international"
    Then I should see 10 "td" elements

  Scenario: Mark orders as "completed"
    Given I am at "/admin/orders/fulfil_international"
    When I check the box "views_bulk_operations[0]"
    And I check the box "views_bulk_operations[1]"
    And I check the box "views_bulk_operations[2]"
    And I select "rules_component::rules_commerce_order_status_completed" from "edit-operation"
    And I press "Apply"
    Then I should see 7 "tr" elements

  Scenario: View international orders with status "completed"
    Given I am at "/admin/orders/fulfil_international"
    When I select "completed" from "edit-status"
    Then I should see 6 "tr" elements
