
typedef struct 
{
	const char *str;
	int pos;
	int errno;
} context;

typedef int (*HIGH_OPER)(context &ctx);
typedef bool (*IS_LOW_OPT)(context &ctx);

int add_sub(context &ctx);

void parse_right_bracket(context &ctx)
{
	if (ctx.str[ctx.pos] == ')')
	{
		ctx.pos++;
	}
}

int parse_opt(context &ctx)
{
	return ctx.str[ctx.pos++];
}

int parse_bracket_num(context &ctx)
{
	int Result = 0;

	if (ctx.str[ctx.pos] == '(')
	{
		ctx.pos++;
		Result = add_sub(ctx);
		parse_right_bracket(ctx);
	} else if (ctx.str[ctx.pos] >= '0' && ctx.str[ctx.pos] <= '9')
	{
		Result = ctx.str[ctx.pos++] - '0';
	} else
	{
		ctx.errno = -1;
	}

	return Result;
}

bool is_mul_or_div(context &ctx)
{
	return ctx.str[ctx.pos] == '*' || ctx.str[ctx.pos] == '/';
}

bool is_add_or_sub(context &ctx)
{
	return ctx.str[ctx.pos] == '+' || ctx.str[ctx.pos] == '-';
}

int calc(int left, char opt, int right)
{
	int Result = 0;

	if (opt == '+')
	{
		Result = left + right;
	}
	else if (opt == '-')
	{
		Result = left - right;
	}
	else if (opt == '*')
	{
		Result = left * right;
	}
	else if (opt == '/')
	{
		Result = left / right;
	}

	return Result;
}

int oper(context &ctx, HIGH_OPER pHighOper, IS_LOW_OPT pIsLowOpt)
{
	int Result = pHighOper(ctx);;

	while (pIsLowOpt(ctx)) 
	{
		char Opt = parse_opt(ctx);
		int Right = pHighOper(ctx);	
		Result = calc(Result, Opt, Right);
	}

	return Result;
}



int mul_div(context &ctx)
{
	return oper(ctx, parse_bracket_num, is_mul_or_div);
}

int add_sub(context &ctx)
{
	return oper(ctx, mul_div, is_add_or_sub);
}

int expr(const char *str)
{
	context ctx = {str, 0};
	int Result = add_sub(ctx);
	if (ctx.errno == -1)
	{
		return -1;
	}
	return Result;
}

int expr_bracket_addsub(const char *str)
{
	context ctx = {str, 0};
	int Result = parse_bracket_num(ctx);

	while (is_add_or_sub(ctx))
	{
		char Opt = parse_opt(ctx);
		int Right = parse_bracket_num(ctx);
		Result = calc(Result, Opt, Right);
	}

	return Result;
}

int expr_bracket_muldiv(const char *str)
{
	context ctx = {str, 0};
	int Result = 0;

	// parse_left_bracket(ctx);
	Result = parse_bracket_num(ctx);
	parse_right_bracket(ctx);

	while (is_mul_or_div(ctx))
	{
		char Opt = parse_opt(ctx);
		int Right = parse_bracket_num(ctx);
		Result = calc(Result, Opt, Right);
	}

	return Result;
}