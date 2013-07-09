class SearchString {

    private static final String STR = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><CS_Mservice_Main generator=\"eworks\" version=\"1.0\"><userCheckInAndroid><user><profile_id>32293</profile_id><user_id>32293</user_id><type>check-ins</type><group>115579</group><photo>csusers32293-AVMSPDGE_img.jpg</photo><created_on>2013-06-11 09:23:31</created_on><status>1</status><event_id>0</event_id><webcam_on>1</webcam_on><mesg>hi</mesg><checkin_id>115579</checkin_id></user><new_checkin_id>115579</new_checkin_id><status>success</status></userCheckInAndroid></CS_Mservice_Main>";

    public static void main(String[] args)
    {
        String pat1 = new String("<new_checkin_id>");
        String pat2 = new String("</new_checkin_id>");
        int i1 = STR.indexOf(pat1);
        if (i1 == -1) {
            System.out.println("not found: " + pat1);
            return;
        }
        i1 += pat1.length();
        int i2 = STR.indexOf(pat2, i1);
        if (i2 == -1) {
            System.out.println("not found: " + pat2);
            return;
        }

        String id = STR.substring(i1, i2);

        System.out.println("new checkin id: " + id);
    }
}
