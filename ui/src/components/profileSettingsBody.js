import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import List, { ListItem, ListItemIcon, ListItemSecondaryAction, ListItemText, ListSubheader } from 'material-ui/List';
import TextField from 'material-ui/TextField';
import Typography from 'material-ui/Typography';
import Button from 'material-ui/Button';
import FingerprintIcon from 'material-ui-icons/Fingerprint';
import ShortTextIcon from 'material-ui-icons/ShortText';
import Avatar from 'material-ui/Avatar';
import ButtonBase from 'material-ui/ButtonBase';

const styles = theme => ({
  ProfileSettingsBodyBody: {
    height: 'calc(100vh - 80px)',
    overflow: 'auto',
  },
  ProfileSettingsBodyAvatar: {
    cursor: 'pointer',
  },
  ProfileSettingsBodyIcon: {
    width: '40px',
    height: '40px',
  },
  ProfileSettingsBodyToxid: {
    flex: 1,
  },
});

class ProfileSettingsBody extends React.Component {
  constructor(props) {
    super(props);
    this.state = {};
    this.classes = props.classes;
  }

  handleProps(props) {
    var result = {
      nickname: props.nickname || "",
      statusMessage: props.statusMessage || "",
      toxid: props.toxid || "",
      profilePassword: props.profilePassword || "",
      avatarSrc: props.avatarSrc || "",
    };
    return result;
  }
  
  render() {
    this.safeProps = this.handleProps(this.props);
    return (    
      <Grid item className={ this.classes.ProfileSettingsBodyBody }>
        <List subheader={<ListSubheader disableSticky>Public</ListSubheader>}>
          <ListItem>
            <ListItemIcon className={ this.classes.ProfileSettingsBodyIcon }>
              <ButtonBase centerRipple>
                <Avatar className={ this.classes.ProfileSettingsBodyAvatar } alt="User avatar" src={ this.safeProps.avatarSrc }>
                  { this.safeProps.avatarSrc ? null : this.safeProps.nickname.charAt(0) }
                </Avatar>
              </ButtonBase>
            </ListItemIcon>
            <TextField
              defaultValue={ this.safeProps.nickname }
              label="Name"
              fullWidth
            />
          </ListItem>
          <ListItem>
            <ListItemIcon className={ this.classes.ProfileSettingsBodyIcon }>
              <ShortTextIcon/>
            </ListItemIcon>
            <TextField              
              defaultValue={ this.safeProps.statusMessage }
              label="Status"
              fullWidth
            />
          </ListItem>
          <ListSubheader>
            Tox ID
          </ListSubheader>
          <ListItem>
            <ListItemIcon className={ this.classes.ProfileSettingsBodyIcon }>
              <FingerprintIcon/>
            </ListItemIcon>
            <Typography noWrap variant="subheading" className={ this.classes.ProfileSettingsBodyToxid }>
              { this.safeProps.toxid }
            </Typography>
            <Button>
              QR Image
            </Button>
          </ListItem>
        </List>
      </Grid>
    );
  }
} 

ProfileSettingsBody.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(ProfileSettingsBody);
