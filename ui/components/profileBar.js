import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import Typography from 'material-ui/Typography';
import Avatar from 'material-ui/Avatar';
import ButtonBase from 'material-ui/ButtonBase';
import 'typeface-roboto';

const styles = theme => ({
  profileBar: {
    overflow: 'hidden',
    minHeight: '120px',
    padding: '20px',
    backgroundColor: theme.palette.primary.main,
  },
  profileBarAvatar: {
    width: '50px',
    height: '50px',
    margin: '10px',
    backgroundColor: theme.palette.secondary.main,
    cursor: 'pointer',
  },
  profileBarNickname: {
    fontWeight: '500',
    fontSize: '14px',
    color: theme.palette.primary.contrastText,
  },
  profileBarStatus: {
    fontWeight: '300',
    color: theme.palette.primary.contrastText,
  },
});

class ProfileBar extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      nickname: props.nickname || "User",
      status: props.status || "User status",
      avatarSrc: props.avatarSrc || "",  
      avatarClickCallback: props.avatarClickCallback || (() => {}),
    }
    this.classes = props.classes;
  }
  
  render() {
    return (    
      <Grid item align="center" className={ this.classes.profileBar }>
        <Grid item>
          <ButtonBase centerRipple onClick={this.state.avatarClickCallback}>
            <Avatar className={ this.classes.profileBarAvatar } alt="User avatar" src={ this.state.avatarSrc }>
              { this.state.avatarSrc ? null : this.state.nickname.charAt(0) }
            </Avatar>
          </ButtonBase>
        </Grid>
        <Grid item xs={10}>
          <Typography align="center" noWrap gutterBottom className={ this.classes.profileBarNickname }>
            { this.state.nickname }
          </Typography>
        </Grid>
        <Grid item xs={10}>
          <Typography variant="caption" align="center" noWrap gutterBottom className={ this.classes.profileBarStatus }>
            { this.state.status }
          </Typography>
        </Grid>
      </Grid>
    );
  }
}

ProfileBar.propTypes = {
  classes: PropTypes.object.isRequired,
  avatarSrc: PropTypes.string,
  nickname: PropTypes.string,
  status: PropTypes.string,
};

export default withStyles(styles)(ProfileBar);
