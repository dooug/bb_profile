A store
=======

Where you can buy something, on the internet. Electronic Commerce.

Test
----

A test suite lives in `tests/`. Tests are run using [PhantomJS](http://phantomjs.org/), [Behat](http://behat.org), [Mink Extension](http://extensions.behat.org/mink/), and [Drupal Extension](https://github.com/jhedstrom/drupalextension).

Change `base_url` in tests/behat.yml to point at your running test instance.

```
# install phantomjs
npm install -g phantomjs
# run phantomjs:
phantomjs --webdriver=8643 &
# set up behat/mink
cd tests
curl -s https://getcomposer.org/installer | php
php composer.phar install
./bin/behat --init
./bin/behat -dl
./bin/behat features/
```

License
-------

Copyright 2014, Thermitic LLC. This software is distributed under the terms of the GNU General Public License.

