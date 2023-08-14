import { Injectable } from '@nestjs/common';
import { PassportStrategy } from '@nestjs/passport';
import { Strategy } from 'passport-oauth2';

@Injectable()
export class FortyTwoStrategy extends PassportStrategy(Strategy, 'ft') {
  constructor() {
    super({
      authorizationURL: '',
      tokenURL: 'https://api.intra.42.fr/oauth/token',
      clientID: '',
      clientSecret: '',
      callbackURL: 'http://localhost:3000/auth/redirect',
	  scope: ['public'],
    });
  }

  async validate(accessToken: string, refreshToken: string) {
    try {
      console.log('accessToken: ', accessToken);
      console.log('refreshToken: ', refreshToken);
      return accessToken;
    } catch (error) {
      console.log(error);
    }
  }
}