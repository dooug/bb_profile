#!/bin/sh
lessc --compress --source-map=css/style.map --source-map-rootpath=/profiles/onboard_profile/themes/onboard_theme/ --source-map-basepath=`pwd` less/style.less > css/style.css
