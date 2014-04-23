<?php

use Behat\Behat\Exception\PendingException;
use Behat\Behat\Context\Step\When;
use Behat\Behat\Context\Step\Then;
use Behat\Gherkin\Node\TableNode;

use Drupal\Component\Utility\Random;

use Drupal\DrupalExtension\Context\DrupalContext;

class FeatureContext extends DrupalContext
{

  /**
   * @Given /^orders:$/
   */
  public function orders(TableNode $table) {
    $rand = new Random();

    foreach ($table->getHash() as $order) {
      $this->visit('/');
      $this->fillField('qty_ctl_3', $order['qty']);
      $this->clickLink('Express Checkout');
      sleep(3);
      $this->assertUrlRegExp('/.*checkout.*/');

      $this->fillField('account[login][mail]', $order['name'] . '@example.com');
      $this->fillField('customer_profile_billing[commerce_customer_address][und][0][name_line]', $order['name']);
      if ($order['shipto'] == 'us') {
        $this->fillField('customer_profile_billing[commerce_customer_address][und][0][country]', 'US');
        sleep(3);
        $this->fillField('customer_profile_billing[commerce_customer_address][und][0][thoroughfare]', $rand->string());
        $this->fillField('customer_profile_billing[commerce_customer_address][und][0][locality]', $rand->string());
        $this->fillField('customer_profile_billing[commerce_customer_address][und][0][administrative_area]', 'MI');
        $this->fillField('customer_profile_billing[commerce_customer_address][und][0][postal_code]', '12345');
      }
      else {
        $this->fillField('customer_profile_billing[commerce_customer_address][und][0][country]', 'TW');
        sleep(3);
        $this->fillField('customer_profile_billing[commerce_customer_address][und][0][thoroughfare]', $rand->string());
        $this->fillField('customer_profile_billing[commerce_customer_address][und][0][postal_code]', '12345');
        $this->fillField('customer_profile_billing[commerce_customer_address][und][0][locality]', $rand->string());
        $this->fillField('customer_profile_billing[commerce_customer_address][und][0][administrative_area]', 'Peiping');
      }

      $this->fillField('edit-commerce-payment-payment-details-credit-card-owner', $order['name']);
      $this->fillField('edit-commerce-payment-payment-details-credit-card-number', '4242424242424242');
      $this->fillField('edit-commerce-payment-payment-details-credit-card-code', '666');

      switch ($order['status']) {
        case 'pending':
          $this->visit('/');
          $this->reset();
          break;
        case 'processing':
          $this->pressButton('edit-continue');
          sleep(5);
          $this->assertUrlRegExp('/.*checkout.*complete.*/');
          break;
        case 'complete':
          throw new Pending('todo: complete orders');
          break;
      }
    }
  }

}
