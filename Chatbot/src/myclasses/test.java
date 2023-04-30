package myclasses;

import org.json.JSONObject;

import java.net.HttpURLConnection;
import java.net.ProtocolException;
import java.net.URL;
import java.net.http.HttpClient;

public class test {
    private static String API_KEY = "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";
    final String GPT_Version = "gpt-3-5-turbo";
    private HttpClient client = HttpClient.newHttpClient();
    private static final String GPT_URI = "https://api.openai.com/v1/chat/completions";
    public static String main(String[] args) throws Exception {
        URL curlreq = new URL(GPT_URI);
        HttpURLConnection conn = (HttpURLConnection) curlreq.openConnection();
        JSONObject body = new JSONObject("config.json");
        JSONObject res = new JSONObject();
        body.append("value", "Who is markipkier?");

        conn.setRequestMethod("POST");
        conn.setRequestProperty("Authorization", "Bearer "+API_KEY);
        conn.setRequestProperty("Content-type", "application/json");
        conn.setDoOutput(true);

        System.out.println();
        return "";
    }
}
