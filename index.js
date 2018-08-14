
import { NativeModules } from 'react-native';

const Xtremepush = require('react-native').NativeModules.Xtremepush;

export default Xtremepush;


function hitEvent(event){
    Xtremepush.hitEvent(event);
}

function hitTag(tag){
    Xtremepush.hitTag(event);
}

function hitTagWithValue(tag, value){
    Xtremepush.hitTag(event);
}

function openInbox(){
    Xtremepush.openInbox();
}

function setUser(user){
    Xtremepush.setUser(user);
}

function setExternalId(id){
    Xtremepush.setExternalId(id);
}


