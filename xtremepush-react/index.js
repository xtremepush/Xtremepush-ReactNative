
import { NativeModules } from 'react-native';

const RNXtremepushReact = require('react-native').NativeModules.RNXtremepushReact;

export default RNXtremepushReact;


function hitEvent(event){
    RNXtremepushReact.hitEvent(event);
}



