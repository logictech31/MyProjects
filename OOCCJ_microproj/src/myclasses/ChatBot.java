package myclasses;

import org.json.JSONArray;
import org.json.JSONObject;

import java.net.*;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class ChatBot {
    private String API_KEY = "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";
    private HttpClient client = HttpClient.newHttpClient();
    private static final URI GPT_URI;

    static {
        try {
            GPT_URI = new URI("https://api.openai.com/v1/chat/completions");
        } catch (URISyntaxException e) {
            throw new RuntimeException(e);
        }
    }

    public String prompthandler(String args) throws Exception{
        JSONObject body = new JSONObject("{\n" +
                "  \"model\": \"gpt-3.5-turbo\",\n" +
                "  \"messages\": [ {\n" +
                "    \"role\": \"user\",\n" +
                "    \"content\": \""+args+"\"\n" +
                "    }\n" +
                "  ],\n" +
                "  \"temperature\": 1,\n" +
                "  \"max_tokens\": 128\n" +
                "}");
        HttpRequest request = (HttpRequest) HttpRequest.newBuilder()
                        .uri(GPT_URI)
                                .header("Content-type", "application/json")
                                        .header("Authorization", "Bearer "+API_KEY)
                                                .POST(HttpRequest.BodyPublishers.ofString(body.toString()))
                                                    .build();

        HttpResponse<String> res = client.send(request, HttpResponse.BodyHandlers.ofString());
        String resobj = res.body();
        JSONObject resob = new JSONObject(resobj);
        JSONArray res2 = (JSONArray) resob.get("choices"); // {, ,, [message: {content: "abcd"}]}
        JSONObject ob = res2.getJSONObject(0);
        JSONObject ob2 = (JSONObject) ob.get("message");
        String finalOb = (String) ob2.get("content");

        // System.out.println(msg);
        return finalOb;
    }
    public String prompt(String args) throws Exception {
        String result = "";
        args = args.toLowerCase();
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        DateTimeFormatter d = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        DateTimeFormatter h = DateTimeFormatter.ofPattern("HH:mm:ss");
        DateTimeFormatter greet = DateTimeFormatter.ofPattern("HH");

        LocalDateTime now = LocalDateTime.now();

        if(args.contains("date") && args.contains("time")) {
            result = "Today's date and time is "+ dtf.format(now);
        } else if(args.contains("date") && (!args.contains("time"))) {
            result = "Today's date is " + d.format(now);
        } else if(args.contains("time") && (!args.contains("date"))) {
            result = "The time right now is "+h.format(now);
        } else if (args.contains("hi") || args.contains("hello") || args.contains("yo")) {
            result = "Hello!";
        }
        else {
            return prompthandler(args);
        }

        return result;
    }
}
