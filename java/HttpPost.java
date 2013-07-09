import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.mime.HttpMultipartMode;
import org.apache.http.entity.mime.MultipartEntity;
import org.apache.http.entity.mime.content.StringBody;

class HttpPost {
    public static void main(String[] args)
    {
        HttpPost postRequest = new HttpPost("https://www.oncam.com/mservice/index");
        MultipartEntity reqEntity = new MultipartEntity(HttpMultipartMode.BROWSER_COMPATIBLE);
        reqEntity.addPart("method", new StringBody("userCheckInAndroid"));
        reqEntity.addPart("user_id", new StringBody("12345"));

        System.out.println("postRequest: " + postRequest);
    }
}
