<?php
session_start();

class Session {
    /**
     * @return bool True, if user is logged in
     */
    public static function isLoggedIn() { return !empty(self::getUserInfo()); }

    private static $loggedInUser;

    /**
     * @return MUser|null Info about logged in user, NULL is not logged in
     */
    public static function getUserInfo() {
        if (empty(@$_SESSION['session_user'])) { return null; }
        else if (empty(self::$loggedInUser)) {
            $user = new MUser();
            $user->id = $_SESSION['session_user']['id'];
            $user->username = $_SESSION['session_user']['name'];
            $user->is_admin = $_SESSION['session_user']['is_admin'];
            $user->is_batch = $_SESSION['session_user']['is_batch'];
            $user->mail = $_SESSION['session_user']['mail'];
            self::$loggedInUser = $user;
        }
        return self::$loggedInUser;
    }

    /**
     * Logs in the given user
     * @param $user MUser
     */
    public static function login($user) {
        $_SESSION['session_user']['id'] = $user->id;
        $_SESSION['session_user']['name'] = $user->username;
        $_SESSION['session_user']['is_admin'] = $user->is_admin;
        $_SESSION['session_user']['is_batch'] = $user->is_batch;
        $_SESSION['session_user']['mail'] = $user->mail;
        $_SESSION['session_user']['login_at'] = date('U');
        self::$loggedInUser = $user;
    }

    /** Destroys the current session and therefor logs the user out */
    public static function logout() {
        $_SESSION['session_user'] = null;
        session_destroy();
        session_unset();
        session_start();
    }

    /**
     * @param $key string
     * @return mixed
     */
    public static function getSessionInfo($key) {
        return $_SESSION['session_user'][$key];
    }

    /**
     * @param $key string Session Info Key
     * @param $value mixed
     */
    public static function setSessionInfo($key, $value) {
        $_SESSION['session_user'][$key] = $value;
    }
}