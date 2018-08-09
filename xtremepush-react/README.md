
# react-native-xtremepush-react

## Getting started

`$ npm install react-native-xtremepush-react --save`

### Mostly automatic installation

`$ react-native link react-native-xtremepush-react`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-xtremepush-react` and add `RNXtremepushReact.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNXtremepushReact.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import ie.imobile.xtremepush.react.RNXtremepushReactPackage;` to the imports at the top of the file
  - Add `new RNXtremepushReactPackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-xtremepush-react'
  	project(':react-native-xtremepush-react').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-xtremepush-react/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-xtremepush-react')
  	```


## Usage
```javascript
import RNXtremepushReact from 'react-native-xtremepush-react';

// TODO: What to do with the module?
RNXtremepushReact;
```
  