
import { NativeModules } from 'react-native';

const RNXtremepushReact = require('react-native').NativeModules.RNXtremepushReact;

export default RNXtremepushReact;


function hitEvent(event){
    RNXtremepushReact.hitEvent(event);
}

function hitTag(tag){
    RNXtremepushReact.hitTag(event);
}

function hitTagWithValue(tag, value){
    RNXtremepushReact.hitTag(event);
}

function openInbox(){
    RNXtremepushReact.openInbox();
}

function setUser(user){
    RNXtremepushReact.setUser(user);
}

function setExternalId(id){
    RNXtremepushReact.setExternalId(id);
}


