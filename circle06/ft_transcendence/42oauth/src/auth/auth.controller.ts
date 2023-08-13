import { Controller, Get, Request, UseGuards } from '@nestjs/common';
import { FortyTwoAuthGuard } from './utils/FTgurads';

@Controller('auth')
export class AuthController {

  @Get('42login')
  @UseGuards(FortyTwoAuthGuard)
  handleLogin() {
    return { msg: '42 Authentication' };
  }

  @Get('redirect')
  @UseGuards(FortyTwoAuthGuard)
  handleRedirect() {
    return { msg: 'OK' };
  }
  async login42(@Request() req) {
    return 'success';
  }
}