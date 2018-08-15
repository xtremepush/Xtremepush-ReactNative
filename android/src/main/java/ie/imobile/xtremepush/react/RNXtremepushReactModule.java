
package ie.imobile.xtremepush.react;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;

import static ie.imobile.extremepush.PushConnector.mPushConnector;

import com.facebook.react.bridge.Callback;

public class RNXtremepushReactModule extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;

    public RNXtremepushReactModule(ReactApplicationContext reactContext) {
        super(reactContext);
        this.reactContext = reactContext;
    }

    @Override
    public String getName() {
        return "Xtremepush";
    }

    @ReactMethod
    public void hitTag(String tag) {
        mPushConnector.hitTag(tag);
    }

    @ReactMethod
    public void hitTagWithValue(String tag, String value) {
        mPushConnector.hitTag(tag, value);
    }

    @ReactMethod
    public void hitEvent(String event){
        mPushConnector.hitEvent(event);
    }

    @ReactMethod
    public void hitEventWithValue(String event, String value){
        mPushConnector.hitEvent(event, value);
    }

    @ReactMethod
    public void openInbox(){
        mPushConnector.openInbox(getCurrentActivity());
    }

    @ReactMethod
    public void setUser(String user){
        mPushConnector.setUser(user);
    }

     @ReactMethod
     public void setExternalId(String user){
        mPushConnector.setExternalId(user);
     }
}
